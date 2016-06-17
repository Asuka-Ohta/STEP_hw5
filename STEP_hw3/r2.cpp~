#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string readNumber(string &line, int *index)
{
	int number = 0;
  string token;
	
	while (*index < line.length() && isdigit(line[*index]))
	{
		number = number * 10 + (line[*index] - '0');
		*index += 1;
	}//END while loop //このループです！！
  token = "NUMBER";
  return token;
}//END function readNumber

string* tokenize(string line)
{
	string* tokens = new string[line.length() - 1];
	int index = 0;
	
	while (index < line.length())
	{
		if (isdigit(line[index]))
			tokens[index] = readNumber(line, &index);
    else
      index++;
	}//END while loop
	
	return tokens; 
}//END function tokenize

int main ()
{
	string line = "";
	cout << "<";
	cin >> line;
	
	string* tokens = tokenize(line); 
	
	delete tokens;
}//END function mainstring readNumber(string &line, int &index)
