#include <iostream>
#include <vector>
using namespace std;
class unit{
public:
    double number;
    string type;
};
void readNumber(string line, int &index, vector < shared_ptr<unit> > &tokens){
  double number;
  string::size_type sz;
  number = stod(line, &sz);
  index += sz;
  auto newUnit = make_shared<unit>();
  newUnit->number= number;
  (newUnit->type).append("NUMBER");
  tokens.push_back(newUnit);
}

void readPlus(vector < shared_ptr<unit> > &tokens, int& index){
  auto newUnit = make_shared<unit>();
  newUnit->number= 1;
  (newUnit->type).append("PLUS");
  tokens.push_back(newUnit);
  index = index + 1;
}

void readMinus(vector < shared_ptr<unit> > &tokens, int& index){
  auto newUnit = make_shared<unit>();
  newUnit->number= 1;
  (newUnit->type).append("MINUS");
  tokens.push_back(newUnit);
  index = index + 1;
}

void readMulti(string line, int &index, vector < shared_ptr<unit> > &tokens){
  double answer = 0;
  auto newUnit = make_shared<unit>();
  newUnit->number= 2;
  (newUnit->type).append("MULTI");
  tokens.push_back(newUnit);
  index = index - 1;
}

void readDivide(string line, int &index, vector < shared_ptr<unit> > &tokens){
  double answer = 0;
  auto newUnit = make_shared<unit>();
  newUnit->number= 2;
  (newUnit->type).append("DIVIDE");
  tokens.push_back(newUnit);
  index = index - 1;
}

void tokenize(vector < shared_ptr<unit> > &tokens, string str){
  int index = 0;
  while (index<str.length()){
    if(isdigit(str[index])){
      readNumber(str.substr(index), index, tokens);
    }
    else if(str[index] == '*'){
      readMulti(str.substr(index), index, tokens);
    }
    else if(str[index] == '/'){
      readDivide(str.substr(index), index, tokens);
    }
    else if(str[index] == '+'){
      readPlus(tokens,index);
    }
    else if(str[index] == '-'){
      readMinus(tokens, index);
    }
    else{
      cout << "invalid input" <<endl;
      exit(1);
    }
  }
}

double evaluate(vector < shared_ptr<unit> > tokens){
  string previous = "PLUS";
  double answer = 0;
  for (auto itr = tokens.begin(); itr!= tokens.end();itr++){
    if((*itr)->type=="NUMBER"){
      if(previous == "PLUS"){
	answer += (*itr)->number;
      }
      if(previous == "MINUS"){
	answer -= (*itr)->number;
      }
    }
    else
      previous = (*itr)->type;
  }
  return answer;
}

int main(){
  string line;
  cout << "<";
  cin >> line;
  string::size_type sz;
  stod(line,&sz);
  vector < shared_ptr<unit> > tokens;
  tokenize(tokens, line);
  double answer = evaluate(tokens);
  cout << answer << endl;
  //delete tokens;
}//END function main
