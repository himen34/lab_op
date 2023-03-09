#include "strings.h"
using namespace std;
string create_makenote(short mode) {
    string firstFile = "Firstone.txt";
    int count = 0;
    string line;
    bool checker = true;
    ofstream enter; 
    if (mode == 0)
    {
        enter.open(firstFile); 
    }
    else
    {
        enter.open(firstFile, fstream::app); 
    }
    cout << "Enter the input text... To stop wàriting press '&'" << endl;
    if (enter.is_open()) {
        while (checker) {
            SetConsoleCP(1251);
            getline(cin, line);
            line = encrypter(line);
            if (line.find('&') != string::npos)
            {
                checker = false;
                line.erase(line.end() - 1);
            }
            count == 0 ? enter << line : enter << '\n' << line;
            count++;
        }
        enter.close();
    }
    else {
        cout << "Error opening output file" << endl;
    }
    SetConsoleCP(866);
    return firstFile;
}
    string encrypter(string &g)
    {
        string crypteven = "";
        string cryptodd = "";
        for (int i = 0;i < g.length();i++)
        {
            if (i % 2 != 0)
            {
                crypteven += g[i];
            }
            else
            {
                cryptodd += g[i];
            }
        }
        string f = crypteven + cryptodd;
        return f;
    }

string checkevenstring(string &firstfile)
{
    string secondFile = "Secondone.txt";
    ifstream enter;
    enter.open(firstfile);
    string str;
    ofstream putcher;
    putcher.open(secondFile);
    if (!putcher.is_open())
    {
        cout << "Error" << endl;
    }
    else
    {
        while (!enter.eof())
        {
            str = "";
            getline(enter, str);
            if(str.length()%2==0)
            {
                putcher << str << endl;
            }
        }
        enter.close();
        putcher.close();
        
    }
    return secondFile;
}
void eraseletter(string& filename)
{
    ifstream input_file(filename);
    if (!input_file.is_open())
    {
        cout << "Error opening file " << filename << endl;
        return;
    }

    string temp_filename = "temp_" + filename;
    ofstream output_file(temp_filename);
    if (!output_file.is_open())
    {
        cout << "Error creating temporary file" << endl;
        input_file.close();
        return;
    }

    char letter_to_remove;
    cout << "Enter the letter you want to remove: ";
    SetConsoleCP(1251);
    cin >> letter_to_remove;
    SetConsoleCP(866);

    string line;
    while (!input_file.eof())
    {
        getline(input_file, line);
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] != letter_to_remove)
            {
                output_file << line[i];
            }
        }
        output_file << endl;
    }
    input_file.close();
    output_file.close();
    remove(filename.c_str());
    rename(temp_filename.c_str(), filename.c_str());
   
}
void readFile(string& filename) {
    ifstream input_file(filename);
    cout << "Your" << filename << ":"<<endl;
    if (!input_file.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    string line;
    SetConsoleCP(1251);
    while (getline(input_file, line)) {
        cout << line << endl;
    }
    SetConsoleCP(866);
    input_file.close();
}
short picker() 
{

    short Mode;
    bool Error;

    do {
        Error = false;
        cin >> Mode;
        if ((Mode != 1) && (Mode != 0)) {
            Error = true;
            printf("Error! Try again:\a\n");
            fflush(stdin);
        }
    } while (Error);

    return Mode;
}
void programprogress(short mode)
{
    string nameoffile = create_makenote(mode);
    string nameoffile2 = checkevenstring(nameoffile);
    readFile(nameoffile2);
    eraseletter(nameoffile2);
    readFile(nameoffile);
    readFile(nameoffile2);
}


