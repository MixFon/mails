#include <stdio.h>
#include <wchar.h>
#include <locale.h>
 
int main()
{
    wchar_t *msg = L"Привет, мир!";    
    
    setlocale(LC_CTYPE, "");
    
    wprintf(L"%ls\n", msg); 
    
    return 0;
}
