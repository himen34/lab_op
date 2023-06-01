#pragma once
#include "CDoubleLinkedList.h"
template <typename T>
void listrunner(CDoubleLinkedList<T>& listname, typename CDoubleLinkedList<T>::Iterator& iterator);
int checker();
template <typename T>
void GetInputGeneric(std::ostream& outputStream, std::istream& inputStream, const std::string& Display, const std::string& ErrorMessage, T& EndResult);
void ProgRunner(std::string type);
template <typename T>
void listrunner(CDoubleLinkedList<T>& listname, typename CDoubleLinkedList<T>::Iterator& iterator) {
    bool err = true;
    T value;
    int a = 0;
    cout << "List was succesfully created" << endl;
    do {
        cout << "Pick a num from a list : \n\t 1 - Add an item to a list from back \n \n\t 2 - Add an item to a list from front"
            "\n \n\t 3 - Erase an item to a list from back \n \n\t 4 - Erase an item to a list from front \n \n\t 5 - Show list size "
            "\n \n\t 6 - Check list for element data(iterator) \n \n\t 7 - Returning a int index of element with the same data \n \n\t 8 - Insert an item \n \n\t 9 - Clear the list and exit a program \n ";
        cin.ignore();
        int a = checker();
        switch (a) {
        case 1:
                GetInputGeneric(cout, cin, "Enter the item that u want to add from back:", "Error!", value);
                listname.push_back(value);
                listname.print_list();
                break;
        case 2:
            GetInputGeneric(cout, cin, "Enter the item that u want to add from front:", "Error!", value);
            listname.push_front(value);
            listname.print_list();
            break;
        case 3:
            listname.pop_back();
            listname.print_list();
            break;
        case 4:
            listname.pop_front();
            listname.print_list();
            break;
        case 5:
            cout << "Size of the list is:";
            cout<<listname.size()<<endl;
            break;
        case 6:
            GetInputGeneric(cout, cin, "Enter the value which you want to find: ", "Error!", value);
            iterator = listname.find(value);
            if (iterator != listname.end()) {
                cout << "Your value : " << iterator.Value() << " was founded in the list" << endl;
            }
            else {
                cout << "This value wasn`t founded at list" << endl;
            }
            break; 
            iterator = listname.begin();
        case 7:
              GetInputGeneric(cout, cin, "Enter the value which you want to find: ", "Error!", value);
              a = listname.findValue(value);
              if (a != -1) {
                  cout << "This value was founded in : " << a << " position" << endl;
              }
              else
              {
                  cout << "This value wasn`t founded at list" << endl;
              }
            break;
        case 8:
            GetInputGeneric(cout, cin, "Enter the value which you want to add: ", "Error!", value);
            if (listname.empty()) {
                listname.push_back(value);
                listname.print_list();
                break;
            }
            GetInputGeneric(cout, cin, "Enter the position where you want to add node:", "Error!", a);
            if (a <= 0 || a > listname.size()) {
                cout << "You can`t add the node to this position!" << endl;
                break;
            }
            if (listname.empty()) {
                listname.push_front(value);
            }
            else {
                int temp = 1;
                for (iterator = listname.begin(); iterator != listname.end(); ++iterator)
                {
                    if (a == temp)
                    {
                        listname.InsertNodeBeforePosition(value, iterator);
                    }
                    temp++;
                }
            }
            listname.print_list();
            break;
        case 9:
            listname.clear();
            err = false;
            break;
        }

    } while (err);

}
template<typename T> 
void GetInputGeneric(std::ostream& outputStream, std::istream& inputStream, const std::string& Display, const std::string& ErrorMessage, T& EndResult)
{
    do
    {
        outputStream << Display.c_str();
        if (inputStream.fail())
        {
            inputStream.clear();
            inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        inputStream >> EndResult;
        if (inputStream.fail())
            outputStream << ErrorMessage.c_str();
    } while (inputStream.fail());
    
}






