#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string username{"null"};
string password{"null"};
fstream userData;

void signin();
void signup();

int main()
{
   userData.open("userdata.txt", ios::in);
   if(userData.is_open()){
     cout << "File opened successfully" << endl;
     while(!userData.eof()){
        getline(userData, username, '\n');
        getline(userData, password, '\n');
     }
     if(username != "null" && password != "null")
        signin();
     else
        signup();
   }
   else
    cout << "Error opening file" << endl;

   return 0;
}

void signin(){
  string anw{"n"};
  string tempUname{""};
  string tempPword{""};
  cout << "Account detected. Sign in? [Y/N]" << endl;
  getline(cin, anw);
  if(anw == "y"){
     cout << "Enter username: " << endl;
     getline(cin, tempUname);
     cout << "Enter password: " << endl;
     getline(cin, tempPword);
     if(tempUname == username && tempPword == password)
        cout << "Welcome!" << endl;
     else{
        cout << "Incorrect username or password. Please try again." << endl;
        signin();
     }

  }
  else if(anw == "n")
    return;
  else{
    cout << "response not recognized: " << anw << endl;
    signin();
  }
}

void signup(){
   string anw{"n"};
   string validPword{""};
   cout << "No account detected. Create one? [Y/N]" << endl;
   getline(cin, anw);
   if(anw == "y"){
      cout << "Create username: ";
      getline(cin, username);
      cout << "Create password: ";
      getline(cin, password);
      cout << "Confirm password: ";
      getline(cin, validPword);
      if(password == validPword){
         userData.open("userdata.txt", ios::out);
         if(userData.is_open()){
            cout << "Welcome! saving credentials...." << endl;
            userData << username << endl;
            userData << password << endl;
            userData.close();
         }
         else{
            cout << "error opening file" << endl;
         }
      }
      else{
        cout << "Passwords do not match." << endl;
        signup();
      }
   }
   else if(anw == "n")
    return;
   else{
    cout << "response not recognized: " << anw << endl;
   }
}
