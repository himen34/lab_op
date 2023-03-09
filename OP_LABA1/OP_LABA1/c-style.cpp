#include "c-style.h"
const char* create_makenote_c(short mode) {
    const char* fpath = "Firstone2.txt";
    char line[256];
    bool checker = true;
    FILE* fptr;
    errno_t err;
    if (mode == 0)
    {
        err = fopen_s(&fptr, fpath, "wt");
    }
    else 
    {
        err = fopen_s(&fptr, fpath, "a+");
    }
    if (err != 0 || fptr == NULL)
    {
        printf("Can't create file\n");
    }
    else {
        cout << "Enter the text... To stop wàriting press '&'" << endl;
        while (checker) {
            SetConsoleCP(1251);
            fgets(line, sizeof(line), stdin);
            if (strchr(line, '&') != NULL ) {
                fflush(stdin);
                checker = false;
            }
            else {
                char* encrypted_line = encrypt_c(line);
                    fwrite(encrypted_line, sizeof(char), strlen(encrypted_line), fptr);
            }
        }
        SetConsoleCP(866);
        fclose(fptr);
    }
    return fpath;
}

char* encrypt_c(char* line) {
    if (strlen(line) == 2) {
        return line;
    }
    char* lineeven = new char[5000] {};
    char* lineodd = new char[5000] {};
    for (int i = 0;i < strlen(line)-1;i++)
    {
        if (i % 2 != 0)
        {
            lineeven[i / 2] = line[i];
        }
        else
        {
            lineodd[i / 2] = line[i];
        }
    }
    char* encrypted_line = new char[10000] {};
    for (int i = 0;i < strlen(lineeven);i++)
    {
        encrypted_line[i] = lineeven[i];
        if (i == strlen(lineeven) - 1)
        {
            for (int g = 0;g < strlen(lineodd);g++)
            {
                encrypted_line[i + g+1] = lineodd[g];
                if (g == strlen(lineodd) - 1)
                {
                        encrypted_line[g+i+2] = '\n';
                }
            }
        }
    }

    return encrypted_line;
    delete[] lineeven;
    delete[] lineodd;
    delete[] encrypted_line;
}
const char* checkevenchars_c(const char* filename)
{
    FILE* fptr;
    errno_t err;
    err = fopen_s(&fptr, filename, "r");
    if (err || fptr == NULL)
    {
        printf("Can't open file\n");
        return NULL;
    }
    else
    {
        FILE* fptr2;
        errno_t err2;
        const char* fpath2 = "Secondone2.txt";
        err2 = fopen_s(&fptr2, fpath2, "wt");
        if (err2 != 0 || fptr2 == NULL)
        {
            printf("Can't create file\n");
            fclose(fptr);
        }
        else
        {
            char* buffer = new char[10000] {};
            while (fgets(buffer, 10000, fptr)) 
            {
                if (strlen(buffer)%2!=0)
                {
                    fputs(buffer, fptr2);
                }
            }
            printf("");
            fclose(fptr);
            fclose(fptr2);
            return fpath2;
        }
    }
}
void erase_letter_c(const char* filename)
{
    FILE* fptr;
    errno_t err;
    char* buffer = new char[10000] {};
    err = fopen_s(&fptr, filename, "rt");
    if (err != 0 || fptr == NULL)
    {
        printf("Can't open file\n");
    }
    else
    {
        FILE* fptr2;
        errno_t err2;
        const char* tempfile = "Temp_file.txt";
        err2 = fopen_s(&fptr2, tempfile, "wt");
        if (err2 != 0 || fptr2 == NULL)
        {
            printf("Can't open file\n");
        }
        else
        {
            char letter_to_remove[2] = { '\0' };
            printf("Enter a letter to remove: ");
            SetConsoleCP(1251);
            scanf_s(" %1s", letter_to_remove, 2); 
            while (fgets(buffer, 10000, fptr) != NULL)
            {
                int i = 0;
                while (buffer[i] != '\0')
                {
                    if (buffer[i] != letter_to_remove[0])
                    {
                        fputc(buffer[i], fptr2);
                    }
                    i++;
                }
            }
            fclose(fptr2);
        }
        fclose(fptr);
        delete[] buffer;
        remove(filename);
        rename(tempfile, filename);
        SetConsoleCP(866);
    }
}
void readFile_c(const char* filename)
{
    FILE* fptr;
    errno_t err;
    char* buffer = new char[10000] {};
    err = fopen_s(&fptr, filename, "r");
    if (err != 0 || fptr == NULL)
    {
        printf("Can't open file\n");
    }
    else
        printf("Your %s:\n", filename);
    {
        while (fgets(buffer, 10000, fptr)) { 
            printf("%s", buffer); 
        }

        fclose(fptr);
        delete[] buffer;
    }
}
    
void programprogress_c(short mode)
{
    const char* nameoffile = create_makenote_c(mode);
    const char* nameoffile2 = checkevenchars_c(nameoffile);
    readFile_c(nameoffile2);
    erase_letter_c(nameoffile2);
    readFile_c(nameoffile);
    readFile_c(nameoffile2);
}
  
