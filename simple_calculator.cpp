#include <iostream>
#include <cmath>

using namespace std;

bool isnum(char ch){
   if ((ch == '0') or (ch == '1') or (ch == '2') or (ch == '3') or (ch == '4') or (ch == '5') or (ch == '6') or (ch == '7') or (ch == '8') or (ch == '9')){
      return true;
   }else{
      return false;
   }
}

int chtoi(char ch){
   switch (ch){
      case '0':{
         return 0;
      }
      case '1':{
         return 1;
      }
      case '2':{
         return 2;
      }
      case '3':{
         return 3;
      }
      case '4':{
         return 4;
      }
      case '5':{
         return 5;
      }
      case '6':{
         return 6;
      }
      case '7':{
         return 7;
      }
      case '8':{
         return 8;
      }
      case '9':{
         return 9;
      }
      default:{
         return -1;
      }
   }
}

int main(int argc, char **argv){
   string input;
   int len;
   float result = 0;
   int dos;
   char op;

   bool again = true;

   while (again){
   
      cout << '\t' << "Perators: [+, -, *, /, ^]" << endl;

      cout << "Enter calculation: ";
      cin >> input;
      len = size(input);
      int step = 0;

      cout << input << ": " << len << endl << endl;

      for (int i = 0; i < len;i++){
         if (i == 0){
            result = chtoi(input[i]);
            if (result < 0){
               return -4;
            }
         }else{
            if ((i % 2 == 0)){                    //numbers
               dos = chtoi(input[i]);
               if (dos < 0){
                  throw "Dos error";
               }
               step++;
               if (!eqint(result)){
                  cout << fixed << '\t' << step << ": " << result << op << dos << " = ";
               }else{
                  cout << defaultfloat << '\t' << step << ": " << result << op << dos << " = ";
               }
               switch (op){
                  case '+':{
                     result += dos;
                     break;
                  }
                  case '-':{
                     result -= dos;
                     break;
                  }
                  case '*':{
                     result *= dos;
                     break;
                  }
                  case '/':{
                     result /= dos;
                     break;
                  }
                  case '^':{
                     result = pow(result,dos);
                     break;
                  }
                  default:{
                     throw "calculation error";
                  }
               }
               if (eqint(result)){
                  cout << defaultfloat << result << endl;
               }else{
                  cout << fixed << result << endl;
               }
            }else{                              //operators
               if (!isnum(input[i])){
                  op = input[i];
               }else{
                  throw "Operator error";
               }
            }
         }
      }

      if (eqint(result)){
         cout << defaultfloat << endl << endl << "result: " << result << endl << endl;
      }else{
         cout << fixed << endl << endl << "result: " << result << endl << endl;
      }

      cout << "Again? [y/n]: ";
      cin >> input;
      if (input[0] == 'y'){
         system("clear");
         input = "";
         len = 0;
         result = 0;
         dos = 0;
         op = ' ';
      }else{
         again = false;
      }

   }

   return 0;
}
