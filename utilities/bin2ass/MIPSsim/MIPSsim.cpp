#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <functional>
#include <bitset>
#include <cmath>

using namespace std;

inline string operator "" _s(const char* str, size_t /*length*/)
{ 
    return string(str); 
}

int32_t twosComp2Decimal(string twos_comp32, bool is_signed=false);

class MembershipChecker
{
  map<string, function<bool(string)>> func_map;

public:
  MembershipChecker()
  {
    func_map["CAT1"] = [this](string instruction){ return isCAT1(instruction); };
    func_map["CAT2"] = [this](string instruction){ return isCAT2(instruction); };
    func_map["CAT3"] = [this](string instruction){ return isCAT3(instruction); };

    func_map["NOP"] = [this](string instruction){ return isNOP(instruction); };
    func_map["J"] = [this](string instruction){ return isJ(instruction); };
    func_map["BEQ"] = [this](string instruction){ return isBEQ(instruction); };
    func_map["BNE"] = [this](string instruction){ return isBNE(instruction); };
    func_map["BGTZ"] = [this](string instruction){ return isBGTZ(instruction); };
    func_map["SW"] = [this](string instruction){ return isSW(instruction); };
    func_map["LW"] = [this](string instruction){ return isLW(instruction); };
    func_map["BREAK"] = [this](string instruction){ return isBREAK(instruction); };

    func_map["XOR"] = [this](string instruction){ return isXOR(instruction); };
    func_map["MUL"] = [this](string instruction){ return isMUL(instruction); };
    func_map["ADD"] = [this](string instruction){ return isADD(instruction); };
    func_map["SUB"] = [this](string instruction){ return isSUB(instruction); };
    func_map["AND"] = [this](string instruction){ return isAND(instruction); };
    func_map["OR"] = [this](string instruction){ return isOR(instruction); };
    func_map["ADDU"] = [this](string instruction){ return isADDU(instruction); };
    func_map["SUBU"] = [this](string instruction){ return isSUBU(instruction); };

    func_map["ORI"] = [this](string instruction){ return isORI(instruction); };
    func_map["XORI"] = [this](string instruction){ return isXORI(instruction); };
    func_map["ADDI"] = [this](string instruction){ return isADDI(instruction); };
    func_map["SUBI"] = [this](string instruction){ return isSUBI(instruction); };
    func_map["ANDI"] = [this](string instruction){ return isANDI(instruction); };
    func_map["SRL"] = [this](string instruction){ return isSRL(instruction); };
    func_map["SRA"] = [this](string instruction){ return isSRA(instruction); };
    func_map["SLL"] = [this](string instruction){ return isSLL(instruction); };
  }

  bool operator()(string instruction, string instruction_type)
  {
    return func_map[instruction_type](instruction);
  }

  bool isCAT1(string inst)
  {
    return inst.substr(0, 3) == "001";
  }
  
  bool isCAT2(string inst)
  {
    return inst.substr(0, 3) == "010";  
  }
  
  bool isCAT3(string inst)
  {
    return inst.substr(0, 3) == "100";  
  }
  
  bool isNOP(string inst)
  {
    if(!isCAT1(inst))
      return false;
    return inst.substr(3, 3) == "000";  
  }
  
  bool isJ(string inst)
  {
    if(!isCAT1(inst))
      return false;
    return inst.substr(3, 3) == "001";  
  }
  
  bool isBEQ(string inst)
  {
    if(!isCAT1(inst))
      return false;
    return inst.substr(3, 3) == "010";  
  }
  
  bool isBNE(string inst)
  {
    if(!isCAT1(inst))
      return false;
    return inst.substr(3, 3) == "011";  
  }
  
  bool isBGTZ(string inst)
  {
    if(!isCAT1(inst))
      return false;
    return inst.substr(3, 3) == "100";  
  }
  
  bool isSW(string inst)
  {
    if(!isCAT1(inst))
      return false;
    return inst.substr(3, 3) == "101";  
  }
  
  bool isLW(string inst)
  {
    if(!isCAT1(inst))
      return false;
    return inst.substr(3, 3) == "110";  
  }
  
  bool isBREAK(string inst)
  {
    if(!isCAT1(inst))
      return false;
    return inst.substr(3, 3) == "111";  
  }
  
  bool isXOR(string inst)
  {
    if(!isCAT2(inst))
      return false;
    return inst.substr(3, 3) == "000";  
  }
  
  bool isMUL(string inst)
  {
    if(!isCAT2(inst))
      return false;
    return inst.substr(3, 3) == "001";  
  }
  
  bool isADD(string inst)
  {
    if(!isCAT2(inst))
      return false;
    return inst.substr(3, 3) == "010";  
  }
  
  bool isSUB(string inst)
  {
    if(!isCAT2(inst))
      return false;
    return inst.substr(3, 3) == "011";  
  }
  
  bool isAND(string inst)
  {
    if(!isCAT2(inst))
      return false;
    return inst.substr(3, 3) == "100";  
  }
  
  bool isOR(string inst)
  {
    if(!isCAT2(inst))
      return false;
    return inst.substr(3, 3) == "101";  
  }
  
  bool isADDU(string inst)
  {
    if(!isCAT2(inst))
      return false;
    return inst.substr(3, 3) == "110";  
  }
  
  bool isSUBU(string inst)
  {
    if(!isCAT2(inst))
      return false;
    return inst.substr(3, 3) == "111";  
  }
  
  bool isORI(string inst)
  {
    if(!isCAT3(inst))
      return false;
    return inst.substr(3, 3) == "000";  
  }
  
  bool isXORI(string inst)
  {
    if(!isCAT3(inst))
      return false;
    return inst.substr(3, 3) == "001";  
  }
  
  bool isADDI(string inst)
  {
    if(!isCAT3(inst))
      return false;
    return inst.substr(3, 3) == "010";  
  }
  
  bool isSUBI(string inst)
  {
    if(!isCAT3(inst))
      return false;
    return inst.substr(3, 3) == "011";  
  }
  
  bool isANDI(string inst)
  {
    if(!isCAT3(inst))
      return false;
    return inst.substr(3, 3) == "100";  
  }
  
  bool isSRL(string inst)
  {
    if(!isCAT3(inst))
      return false;
    return inst.substr(3, 3) == "101";  
  }
  
  bool isSRA(string inst)
  {
    if(!isCAT3(inst))
      return false;
    return inst.substr(3, 3) == "110";  
  }
  
  bool isSLL(string inst)
  {
    if(!isCAT3(inst))
      return false;
    return inst.substr(3, 3) == "111";  
  }

  string getInstructionType(string inst)
  {
    if(isCAT1(inst))
    {
      if(isNOP(inst))
        return string{"NOP"};
      if(isJ(inst))
        return string{"J"};
      if(isBEQ(inst))
        return string{"BEQ"};
      if(isBNE(inst))
        return string{"BNE"};
      if(isBGTZ(inst))
        return string{"BGTZ"};
      if(isSW(inst))
        return string{"SW"};
      if(isLW(inst))
        return string{"LW"};
      if(isBREAK(inst))
        return string{"BREAK"};
    }
    else if(isCAT2(inst))
    {
      if(isXOR(inst))
        return string{"XOR"};
      if(isMUL(inst))
        return string{"MUL"};
      if(isADD(inst))
        return string{"ADD"};
      if(isSUB(inst))
        return string{"SUB"};
      if(isAND(inst))
        return string{"AND"};
      if(isOR(inst))
        return string{"OR"};
      if(isADDU(inst))
        return string{"ADDU"};
      if(isSUBU(inst))
        return string{"SUBU"};
    }
    else if(isCAT3(inst))
    {
      if(isORI(inst))
        return string{"ORI"};
      if(isXORI(inst))
        return string{"XORI"};
      if(isADDI(inst))
        return string{"ADDI"};
      if(isSUBI(inst))
        return string{"SUBI"};
      if(isANDI(inst))
        return string{"ANDI"};
      if(isSRL(inst))
        return string{"SRL"};
      if(isSRA(inst))
        return string{"SRA"};
      if(isSLL(inst))
        return string{"SLL"};
    }
    return string{"INT"};
  }
};

class Word32
{
  struct FieldInfo
  {
    int start;
    int end;
    bool is_signed;
    FieldInfo(int s = 0, int e = 0, bool is = false) : start(s), end(e), is_signed(is) {}
  };

  map<string, FieldInfo> _field_info;
  static MembershipChecker _type_checker;
  int _addr;
  string _word;
  bool _size_ok = false;
  bool _is_int = false;

public:
  Word32(): _addr{0} {}
  Word32(string binary_word, int address);
  int getAddress() const { return _addr; }
  string type() const { return _type_checker.getInstructionType(_word); }
  string str() const { return _word; }
  string getField(const char field_name[]) const;
  string repr() const;
  int operator[](string field_name) const;
  bool isInstance(string instruction_type);
  void interpret(); 
};
MembershipChecker Word32::_type_checker = MembershipChecker{};

struct AssemblyCode
{
  vector<Word32> instructions;
  vector<Word32> data;
};

class Disassembler
{
  ifstream _in_file;
  ofstream outfile;
  bool _ok = true;
public:
  Disassembler(string binary_fn);
  AssemblyCode operator()(int start_address);
};

class MIPSsim
{
  int _cycle;
  int32_t _pc;
  int32_t _instruction_start;
  int32_t _data_start;
  vector<Word32> _instructions;
  vector<int> _data;
  int32_t _registers[32];

public:
  void loadCode(AssemblyCode &mips_code);
  string getState();
  void run();
};

int32_t twosComp2Decimal(string twos_comp32, bool is_signed)
{
  // Positive
  if(twos_comp32[0] == '0' || !is_signed)
    return stoi(twos_comp32, nullptr, 2);

  // Negative

  // Invert string
  string inv = twos_comp32;
  for(auto& ch : inv)
  {
    if(ch == '0')
      ch = '1';
    else
      ch = '0';
  }

  // Add one and negate
  return -(stoi(inv, nullptr, 2) + 1);
}

Word32::Word32(string binary_word, int address)
{
  _addr = address;
  _word = binary_word;
  _size_ok = _word.size() == 32;
}

string Word32::getField(const char field_name[]) const
{
  auto offset1 = _field_info.at(field_name).start;
  auto offset2 = _field_info.at(field_name).end;
  return string(_word.begin() + offset1, _word.begin() + offset2);
}

string Word32::repr() const
{
  stringstream ret;
  string i_type = type();
  if(i_type == "INT")
  {
    ret << twosComp2Decimal(_word, true) << endl;
    return ret.str();
  }
  ret << i_type;
  if(_type_checker.isCAT1(_word))
  {
    if(i_type == "NOP")
      ret << endl;
    else if(i_type == "J")
      ret << " #" << operator[]("IMM") * 4 << endl; 
    else if(i_type == "BEQ" || i_type == "BNE")
    {
      ret << " R" << operator[]("SRC1") << ", R" << operator[]("SRC2")
          << ", #" << operator[]("OFFSET") << endl;
    }
    else if(i_type == "BGTZ")
    {
      ret << " R" << operator[]("SRC1") << ", #" << operator[]("OFFSET") << endl;
    }
    else if(i_type == "SW" || i_type == "LW")
    {
      ret << " R" << operator[]("DEST") << ", " << operator[]("OFFSET") << "(R"
          << operator[]("SRC") << ")" << endl;
    }
    else
      ret << endl;  // BREAK
  }
  else if(_type_checker.isCAT2(_word))
  {
    if(i_type == "ADDU" || i_type == "SUBU")
      ret << " R" << operator[]("DEST") << ", R" << operator[]("SRC1") << ", R"
          << operator[]("SRC2") << endl;

    else
      ret << " R" << operator[]("DEST") << ", R" << operator[]("SRC1") << ", R"
          << operator[]("SRC2") << endl;
  }
  else if(_type_checker.isCAT3(_word))
  {
    if(i_type == "SLL" || i_type == "SRA" || i_type == "SRL")
    {
      ret << " R" << operator[]("DEST") << ", R" << operator[]("SRC") << ", #"
          << operator[]("SHIFT") << endl;
    }
    else
    {
      ret << " R" << operator[]("DEST") << ", R" << operator[]("SRC") << ", #"
          << operator[]("IMM") << endl;
    }
  }
  return ret.str();
}

int Word32::operator[](string field_name) const
{
  try
  {
    auto fi = _field_info.at(field_name);
    return twosComp2Decimal(_word.substr(fi.start, fi.end - fi.start), fi.is_signed);
  }
  catch(exception &e)
  {
    cout << __PRETTY_FUNCTION__ << " exception: " << e.what() << endl;
    return 0;
  }
}

bool Word32::isInstance(string instruction_type)
{
  if(instruction_type == "INT")
    return _is_int;
  else
    return _type_checker(_word, instruction_type);
}

void Word32::interpret() // Sets the field name and boundaries for each instruction type
{
  string i_type = type();
  if(_type_checker.isCAT1(_word))
  {
    if(i_type == "NOP")
      _field_info["NULL"] = FieldInfo(6, 32);
    else if(i_type == "J")
      _field_info["IMM"] = FieldInfo(6, 32);
    else if(i_type == "BEQ" || i_type == "BNE" || i_type == "BGTZ")
    {
      _field_info["SRC1"] = FieldInfo(6, 11);
      _field_info["SRC2"] = FieldInfo(11, 16);
      _field_info["OFFSET"] = FieldInfo(16, 32, true);
    }
    else if(i_type == "SW" || i_type == "LW")
    {
      _field_info["SRC"] = FieldInfo(6, 11);
      _field_info["DEST"] = FieldInfo(11, 16);
      _field_info["OFFSET"] = FieldInfo(16, 32, true);
    }
    else
      _field_info["BREAK"] = FieldInfo(16, 32);
  }
  else if(_type_checker.isCAT2(_word))
  {
    if(i_type != "MUL" && i_type != "ADD" && i_type != "SUB")
    {
      _field_info["DEST"] = FieldInfo(6, 11);
      _field_info["SRC1"] = FieldInfo(11, 16);
      _field_info["SRC2"] = FieldInfo(16, 21); 
    }
    else
    {
      _field_info["DEST"] = FieldInfo(6, 11, true);
      _field_info["SRC1"] = FieldInfo(11, 16, true);
      _field_info["SRC2"] = FieldInfo(16, 21, true); 
    }

  }
  else if(_type_checker.isCAT3(_word))
  {
    if(i_type == "SLL" || i_type == "SRA" || i_type == "SRL")
    {
      _field_info["DEST"] = FieldInfo(6, 11);
      _field_info["SRC"] = FieldInfo(11, 16);
      _field_info["SHIFT"] = FieldInfo(27, 32, true);
    }
    else if(i_type == "ORI" || i_type == "XORI" || i_type == "ANDI")
    {
      _field_info["DEST"] = FieldInfo(6, 11);
      _field_info["SRC"] = FieldInfo(11, 16);
      _field_info["IMM"] = FieldInfo(16, 32);
    }
    else // ADDI, SUBI
    {
      _field_info["DEST"] = FieldInfo(6, 11, true);
      _field_info["SRC"] = FieldInfo(11, 16, true);
      _field_info["IMM"] = FieldInfo(16, 32, true);
    }
  }
  else
    _field_info["INT"] = FieldInfo(0, 32, true);
}

Disassembler::Disassembler(string binary_fn) : _in_file{binary_fn}
{
  _ok = (bool)_in_file;
  if(!_ok)
    cout << "Error encountered with file " << binary_fn << endl;
}

AssemblyCode Disassembler::operator()(int start_address)
{
  int addr = start_address;
  AssemblyCode mips_out;
  outfile.open("disassemly.txt");

  auto *word_buffer = &mips_out.instructions;
  string line;
  while(getline(_in_file, line, '\n'))
  {
    Word32 word{line.substr(0, 32), addr};
    word.interpret();
    outfile << word.str() << '\t' << word.getAddress() << '\t' << word.repr();
    addr += 4;
    word_buffer->push_back(word);
    if(word_buffer == &mips_out.instructions && word.isInstance("BREAK"))
      word_buffer = &mips_out.data;
  }

  return mips_out;
}

void MIPSsim::loadCode(AssemblyCode &mips_code)
{
  _cycle = 1;
  _instructions = mips_code.instructions;
  _pc = _instruction_start = _instructions[0].getAddress();
  for(auto& data_word : mips_code.data)
    _data.push_back(twosComp2Decimal(data_word.str()));
  _data_start = mips_code.data[0].getAddress();
  for(auto& reg : _registers)
    reg = 0;
}

string MIPSsim::getState()
{
  stringstream output;
  int32_t (&R)[32] = _registers;
  vector<int> &D = _data;
  output << string(20, '-') << endl
         << "Cycle " << _cycle << ":\t" << _pc << _instructions[_pc - _instruction_start / 4].str() << endl
         << endl
         << "Registers" << endl
         << "R00:\t" << R[0]  << '\t' << R[1]  << '\t' << R[2]  << '\t' << R[3]  << '\t'
                     << R[4]  << '\t' << R[5]  << '\t' << R[6]  << '\t' << R[7]  << '\t' << endl
         << "R08:\t" << R[8]  << '\t' << R[9]  << '\t' << R[10] << '\t' << R[11] << '\t'
                     << R[12] << '\t' << R[13] << '\t' << R[14] << '\t' << R[15] << '\t' << endl
         << "R16:\t" << R[16] << '\t' << R[17] << '\t' << R[18] << '\t' << R[19] << '\t'
                     << R[20] << '\t' << R[21] << '\t' << R[22] << '\t' << R[23] << '\t' << endl
         << "R24:\t" << R[24] << '\t' << R[25] << '\t' << R[26] << '\t' << R[27] << '\t'
                     << R[28] << '\t' << R[29] << '\t' << R[30] << '\t' << R[31] << '\t' << endl
         << endl
         << "Data" << endl;
  stringstream data_line;
  for(size_t i = 0; i < _data.size(); i++)
  {
    if(i % 8 == 0)
      data_line << _data_start + i * 4 << ':';
    data_line << '\t' << D[i];
    if(i % 8 == 7)
    {
      data_line << endl;
      output << data_line;
      data_line.str("");
      data_line.clear();
    }
  }
  output << endl;
  return output.str();
}


int main(int argc, char *argv[])
{
  if(argv[1] == nullptr)
    return -1;
  string input_fn{argv[1]};
  cout << "Input filename: \"" << input_fn << "\"" << endl;
  int start_address = 64;

  Disassembler disassembler{input_fn};
  AssemblyCode mips_code = disassembler(start_address);

  cout << "Instructions" << endl;
  for(auto& i : mips_code.instructions)
    cout << i.getAddress() << '\t' << i.str() << endl;
  cout << "Data" << endl;
  for(auto& i : mips_code.data)
    cout << i.getAddress() << '\t' << i.str() << endl;

  return 0;
}
