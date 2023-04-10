#include "functions_binary.h"
int main()
{
    Date today;
    time_t now = time(0);
    struct tm ltm;
    localtime_s(&ltm, &now);
    today.day = ltm.tm_mday;
    today.month = ltm.tm_mon + 1;
    today.year = ltm.tm_year + 1900;
    const string filename = create_write_binary();
    firsttask(filename, today);
    secondtask(filename);
}