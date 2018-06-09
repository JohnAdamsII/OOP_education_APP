#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
//#include <Exam_replace.h>




using namespace std;

void menu();
void createpassword(string Username);
string createnewpassword(string username);
void login();
bool valid = false;
void UpdateGem(string text);
bool splitstring (string s, string match, string &a, string &b);
void general_login();
bool loggin = false;
void display_student_scores();
void display_exam_scores();
void column_counter();
int columns;
void display_student_average();
bool print_exam_average = false;
void add_exam(vector<int> data);
vector<int> input;
void addRow(string newUser, vector<int> data);
int NUM_OF_STUD; // aka number of rows
void curve_exam();





//Testing
string ID;

vector<int> read_numbers(string file_name);
void replaceRow(string username, string data);
void Exam_Replace_Driver();



//Testing






















class User {

   // private:
        string username;
        string password;

    public:
        User()
        {
           username = "jadams70";
           password = "swag";
        }

        void showUsername()
        {
            cout << username;
        }

        void setUsername(string U)
        {
            username = U;
        }

        ~User()
        {

        }


};


void column_counter()
{



    int x;
    ifstream inFile;
    string dummy;
    int counter = 0;

    inFile.open("scores.txt");

    inFile >> dummy;
    while (inFile >> x) {
        counter++;
    }

    inFile.close();
    //cout << "columns = " << counter << endl;
    //counter++;
    columns = counter;
    //cout << "columns = " << counter << endl; //test  //This is alwyas running why??





}

void curve_exam()
{
    int curve;
    int exnum;
    cout << "Enter Exam Number: ";
    cin >> exnum;
    cout << "Enter curve: ";
    cin >> curve;





}



void menu()
{
    int select;
    string str;


    cout << "MENU";

    cout << "\n(1)  - Create a new user\n(2)  - Change password\n(3)  - Display scores of a student\n(4)  - Display scores of an exam\n(5)  - Display avg score of a student\n(6)  - Display avg score of an exam\n(7)  - Insert scores of a new exam to all students\n(8)  - Insert scores of all exams of a student who is not in file\n(9)  - Update an exam score of a student\n(10) - Update an exam score for every student\n(11) - Quit\n   ";



    cout << "\nPlease make a selection: ";
    cin >> select;


    //if(isalpha(select))
    //exit(0);
    //cout << "Please enter a number: ";

    switch(select)

    {
        case 1:
            cout << "Enter Desired Username: ";
            cin >> str;
            User* ptr; //pointer to object
            ptr = new User; //dynamic object creation
            ptr->setUsername(str);
           // ptr->showUsername(); //accessing member through pointer to object
            cout << "\n";
            createpassword(str);


            delete ptr;

            break;

        case 2:
            login();
            //if (valid == true)
            break;
        case 3:
            general_login();
            if (loggin ==true)
               display_student_scores();
            else{
                cout << "Not logged in, Try again!\n";
            }

            break;

        case 4:
            general_login();
            if (loggin ==true)
               display_exam_scores();
            else{
                cout << "Not logged in, Try again!\n";
            }

            break;

        case 5:
            general_login();
            if (loggin ==true)
            display_student_average();
            break;


        case 6:
            print_exam_average = true;
            general_login();
            if (loggin ==true)
            display_exam_scores();
            break;

        case 7:
            general_login();

            if (loggin ==true)
            {
                cout << "Enter exam Scores: ";    // Make 5 dynamic by getting num of rows

                for(int i=0; i < 5;i++)
                    {
                        int temp;
                        cin >> temp;
                        if(cin.bad()){
                        break;
                        }


                        input.push_back(temp);




                    }




                add_exam(input);


            }

            break;

        case 8:
            general_login();
            if (loggin ==true)
            {
                string ID;
                cout << "Enter student ID: ";
                cin  >> ID;
                vector<int> newstu;
                cout << "Enter Exam Scores: ";
                column_counter();
                for(int i=0; i < columns;i++)
                    {

                        int temp3;
                        cin >> temp3;

                        if(cin.bad())
                            {

                                break;
                               // exit(0);



                            }





                       // temp3 = zero;
                        if (temp3 > 100 or temp3 < 0)
                            temp3 = 0;

                        newstu.push_back(temp3);




                    }

                   // for (int j: newstu)
                        //cout << newstu[j];



            addRow(ID,newstu);
            }
            break;


        case 9:
            general_login();
            if (loggin ==true)
            Exam_Replace_Driver();
            break;

        case 10:
            general_login();
           if (loggin ==true)
            {

                curve_exam(); //aaaaaa




            }
           break;







        case 11:
            cout << "Exiting";
            exit(0);
            break;













        default:

            cout << "\n\n Invalid Choice.... Try Again \n\n";
            //cin >> select;
            //menu();

              break;




    }


}

void display_student_scores()

{
    string ID;
    cout << "Enter Student ID: ";
    cin >> ID ;

    ifstream MyFile("scores.txt");
    string line;

    while(getline(MyFile,line)) {

        if(line.find(ID) != string::npos){
            cout << line << endl;
        }

    }

   // cout << ID << " not found" << endl;

    }



void display_exam_scores()
{
    column_counter();
    columns++;
    int COLUMNS = columns;  // figure out how to dynamiclly find number of columns in txt file

    vector< vector <string> > data;

    string filename = "scores.txt";

    ifstream ifile(filename.c_str());


    if (ifile.is_open()) {
        string num;

        vector <string> numbers_in_line;

        while (ifile >> num) {
            numbers_in_line.push_back(num);

            if (numbers_in_line.size() == COLUMNS) {
                data.push_back(numbers_in_line);
                numbers_in_line.clear();
            }
        }
    }
    else {
        cerr << "There was an error opening the input file!\n";
        exit(1);
    }

    int col; //example: the 2nd column
    //now get the column from the 2d vector:
    vector <string> column;
    cout << "Enter Exam Number: ";
    cin >> col;
    col = col + 1;

    cout << "Scores of Exam " << col-1 << endl;
    for (int i = 0; i < data.size(); ++i) {
        column.push_back(data[i][col - 1]);
        cout << column[i] << endl;
    }

    ifile.close();

//     average exam score

   double sum = 0;

  std::vector<int> intNumbers;
for (int i=0; i < data.size(); i++)
    {
     int num = atoi(column.at(i).c_str());
   intNumbers.push_back(num);
    // cout << intNumbers[i] << endl;
    sum += intNumbers[i];
   }

  sum = sum / intNumbers.size();
   if (print_exam_average == true)
   cout << "Average score of Exam "<< col-1 << " is: " << sum << endl;










}







void addRow(string newUser, vector<int> data)
{
    //for (int i: data)
       // cout << i;


    ofstream outfile;
    outfile.open("scores.txt", ios::app);
    outfile << "\n" << newUser;

    for (int i : data)
    {

       outfile << " " << i;


    }

    outfile.close();
















}

























void display_student_average()
{

column_counter();
//make dynamic
string ID;
cout<< "Enter Student ID: ";
cin >> ID;
double x;
double sum = 0;



std::ifstream file("scores.txt");
std::string name;

// This will loop until we can no longer
// extract names from the file.
while (file >> name) {

if (name == ID) {

    while(file >> x)
    {
        sum += x;



    }


   // double a;
   // double b;
    //double c;
    //double d;

    //file >> a >> b >> c >> d;
    //std::cout << name << ' ' << (a + b + c + d)/4 << '\n';

}

//columns--; // idk if needed
double average = sum/columns;  //make sure to make 4 into col

cout << average << "\n";












}



}





void add_exam(vector<int> data)
{

   // for(int i : data)
        //cout << i;

  string filename = "scores.txt";
  ofstream outfile;
  ifstream infile;
  ostringstream ss;
  string out_string;

  int i;
  infile.open(filename,ios::in);
  int n = data.size();
  vector<string>rows;
  string str;

  while(!infile.eof())
    {
        getline(infile,str);
        rows.push_back(str);
    }

    for (i=0; i < n; i++)
    {

        rows[i] += " ";
        ss << data[i];
        ss.str();
        rows[i] += ss.str();
        ss.str("");



    }

    outfile.open(filename,ios::out);
    for (i = 0; i < n - 1; i++)
    {
       outfile << rows[i] << "\n";

    }

    outfile << rows[i];
    outfile.close();
    infile.close();





























}










class Pwdg

{

private:

int length;



char lettersandDigits[73] = {'1','2','3','4','5','6','7','8','9','0','!', '@','#','$','%','^','&','*','+','-','=',

'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',

'r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',

'Q','R','S','T','U','V','W','X','Y','Z'};

public:




Pwdg(int len)

{

length=len;

}

char* getArray()

{

return lettersandDigits;

}

int getLength()

{

return length;

}

void setLength(int l)

{

length=l;

}

string getPWD()

{

srand(time(NULL));

char pass[length+1];

int i;

for( i=0;i<getLength();i++)

{

int randNum = rand() % 73;

pass[i] = lettersandDigits[randNum];

}

pass[i] = '\0';

string passwd(pass);

return passwd;

}

};

class Strong_pwdg : public Pwdg

{

public:

Strong_pwdg(int l) :Pwdg(l)

{

}

string getStrongPWD()

{

char * a = getArray();

if(getLength()<8)

setLength(8);

srand(time(NULL));

int i;

int choice=rand()%2;

char must[4];

if(choice==1)

{

must[0]=a[rand()%10];

must[1]=a[rand()%11+10];

must[2]=a[rand()%26+21];

must[3]=a[rand()%26+47];

cout<<"Four mandatory random chars: "<<must[0]<<" "<<must[1]<<" "<<must[3]<<" "<<must[2]<<endl;

}

else

{

must[2]=a[rand()%10];

must[1]=a[rand()%11+10];

must[0]=a[rand()%26+21];

must[3]=a[rand()%26+47];

cout<<"Four mandatory random chars: "<<must[2]<<" "<<must[1]<<" "<<must[3]<<" "<<must[0]<<endl;

}

char pass[getLength()+1];

int count=0;

for( i=0;i<getLength();i++)

{

choice = rand()%2;

if(choice==0)

{

int randNum = rand() % 73;

pass[i] = a[randNum];

}

else

{

if(count==4)

{

i--;

continue;

}

else{

pass[i]=must[count];

count++;

}

}

}

cout<<"length: "<<getLength()<<" "<<endl;

if(count!=4)

{

i=i-(4-count);

while(i<getLength())

{

pass[i]=must[count++];

i++;

}

}

pass[i] = '\0';

string passwd(pass);

return passwd;

}

};
















void createpassword(string Username)

{

string User = Username;
string password;

int l;

char ch;

cout<<"Enter length of password: ";

cin>> l;

Strong_pwdg p(l);

cout<<"Want a strong password? (Y/N) ";

cin>>ch;

if(ch=='y'||ch=='Y')

password = p.getStrongPWD() ;

else

password = p.getPWD() ;

cout << "Username: "<< User << endl;
cout << "Password: " << password << endl <<"\n";


ofstream myFile("passwords.txt",ios_base::app); // File writing


myFile << User << ' ' << password << endl;

myFile.close();





}


string createnewpassword(string Username)
{


string User = Username;
string password;

int l;

char ch;

cout<<"Enter length of password: ";

cin>> l;

Strong_pwdg p(l);

cout<<"Want a strong password? (Y/N) ";

cin>>ch;

if(ch=='y'||ch=='Y')

password = p.getStrongPWD() ;

else

password = p.getPWD() ;


cout << "New Password: " << password << endl <<"\n";




return password;








}































void login(){

string User;
string Pass;

cout << "Enter Username: " ;        //remove endl?
cin >> User;
cout << "Enter Password: " ;
cin >> Pass;

//string new_pass = "test";


ifstream myFile("passwords.txt");
string User_onfile;
string pass_onfile;

while(myFile >> User_onfile >> pass_onfile)   // file reading
    {

        if(User_onfile==User && pass_onfile==Pass)
        {
        cout << "Login Successful\n";
        valid = true;
        myFile.close();
        string gen_pass = createnewpassword(User);



        UpdateGem(User+" "+gen_pass);
        //rename("passwords2.txt", "passwords.txt");


        }


        //else
        //cout << "Incorrect login";

    }



   // if(valid==true)
     //   {
         //   UpdateGem(User+" swag");


      //  }











}





void UpdateGem(string text) {
    ifstream f;
    ofstream f2;
    vector<string> sGEMS;
    string temp[3];
    bool OverWrite;
    string Delete, line;

    splitstring(text, " ", temp[0], temp[1]);
    sGEMS.reserve(100);
    f.open("passwords.txt");
    while (true) {
        getline(f, line);
        if (f.eof()) break;
        sGEMS.push_back(line);
        splitstring(line, " ", temp[1], temp[2]);
        if (temp[0] == temp[1]) {
            OverWrite = 1;
            Delete = line;
        }
    }
    f.close();
    f2.open("passwords2.txt"/*,std::ios_base::app*/);
    if (OverWrite) {
        for (int i = 0; i < sGEMS.size(); ++i) {
            if (sGEMS[i] != Delete) f2 << sGEMS[i] << std::endl;
        }
    }
    f2 << text << std::endl;
    f2.close();
    remove("passwords.txt");
    rename("passwords2.txt", "passwords.txt");

   // remove("passwords.txt");
   // rename("GEM2.txt", "passwords.txt");
}



bool splitstring (string s, string match, string &a, string &b)
{
    int x = s.find(match);
    if (x != string::npos) {
        a = s.substr(0, x);
        b = s.substr(x+match.size());
        return true;
    }
    return false;
}







void general_login()
{


string User;
string Pass;

cout << "Enter Username: " ;         //remove endl?
cin >> User;
cout << "Enter Password: " ;
cin >> Pass;

//string new_pass = "test";


ifstream myFile("passwords.txt");
string User_onfile;
string pass_onfile;

while(myFile >> User_onfile >> pass_onfile)   // file reading
    {

        if(User_onfile==User && pass_onfile==Pass)
        {
        cout << "Login Successful\n";
        loggin = true;
        myFile.close();


        }









}

}























int main()
{
    while(cin.good())
        {
            menu();
        }


   return 0;

}























// Testing below

void Exam_Replace_Driver()
{

vector<int> returned = read_numbers("scores.txt");


stringstream ss;


string str1;


ss << ID;

for (int i=0;i<returned.size();i++)
{
  ss << " ";
  ss << returned[i];
  str1 += ss.str();
  ss.str("");
}

cout << str1;

replaceRow(ID,str1);


}






vector<int> read_numbers(string file_name)
{
    ifstream infile;
    infile.open(file_name);
    vector<int> numbers;

    //string ID;

    cout << "Enter ID: ";
    cin >> ID;

    int Exam_num;

    cout << "Enter Exam Number: ";
    cin >> Exam_num;

    int grade;

    cout << "Enter Replacement grade: ";
    cin >> grade;



    while(!infile.eof() && !infile.bad()){


   string str;

   infile >> str;

   if (str == ID)
    {
      // string dummy;
      // infile >> dummy;

        int num;
        while(infile >> num)
        {
            numbers.push_back(num);
        }

        break;
    }

infile.ignore(1000,'\n');

    }


    for (int i : numbers)
    cout << i << " ";

    cout << endl;

    for(int i = 0; i < numbers.size();i++)
        {
            if (i== Exam_num-1)
            numbers[i] = grade;


        }

    for (int i : numbers)
    cout << i << " ";
    cout << "\n";
    return numbers;



}





void replaceRow(string username, string data)
{
    ofstream outfile;
    ifstream infile;
	infile.open("scores.txt", ios::in);
	vector<string> file;
	string str;

	while (!infile.eof())
	{
		getline(infile, str);
		file.push_back(str);
	}

	int n = file.size();
	int i;

	for (i = 0; i < n; i++)
	{
		istringstream iss(file[i]);
		iss >> str;
		if (str == username)
		{
			break;
		}
	}
	file[i] = data;
	infile.close();

	outfile.open("scores.txt", ios::out);

	for (i = 0; i < n-1; i++)
	{
		outfile << file[i] << "\n";
	}
	outfile << file[i];
	outfile.close();
}




















