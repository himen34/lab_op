#include "strings.h"
#include "c-style.h"
int main(int argc,char * argv[])
{
    setlocale(LC_ALL, "ukr");
    char mode[] = "-mode";
    char mode1[] = "FilePointer";
    char mode2[] = "FileStream";
    short decision;  
    if (argc != 3 || strcmp(argv[1], mode) != 0)
    {
        cout << "Launch the program with particular mode!\n" <<
            ".exe -mode FilePointer/FileStream\n";
    }
    else if (!strcmp(argv[2], mode1))
    {
        programprogress_c(0);
        do {
            cout << "Do you want to end the program (0) or change the file (1)?" << endl;
            decision = picker();
            cout << '\n';

            if (decision == 1) {
                programprogress_c(1);
            }
        } while (decision != 0);

        cout << "Thank you for using my program!" << endl;

    }
    else if (!strcmp(argv[2], mode2))
    {
        
        programprogress(0);
        do {
            cout << "Do you want to end the program (0) or change the file (1)?" << endl;
            decision = picker();
            cout << '\n';

            if (decision == 1) {
                programprogress(1);
            }
        } while (decision != 0);

        cout << "Thank you for using my program!" << endl;
    }
    else
    {
        cout << "The only modes are FilePointer/FileStream";
    }
}





