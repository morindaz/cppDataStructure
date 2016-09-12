
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <typeinfo>

using namespace std;





int main(){
  ifstream myfile("in.txt");
  string line;
  int Content;
  while(myfile>>Content)
  cout<<Content<<" ";

    string line1;
/*
  while(getline(myfile,line)){

    line1=line;
    cout<<line1<<endl;

  }
*/

cout<<line1<<endl;
 int input,in,del;
  cout<<"Please input the operation:";
  cin>>input;
  if(input == 1){
    cin>>in;


  }
  else if (input==2){

  }
}
