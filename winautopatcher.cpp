#include <iostream>
#include <string>
#include <sys/stat.h>
#include <bits/stdc++.h>
#include <exception>
using namespace std;
char str1[10];
char str2[10];
int server_ver=0;
int local_ver=0;

int main()
	{
system("del current.txt");
system("cls");
system("UberStrike_Data\\updater\\curl.exe -LO https://uberkill.cc/patcher/current.txt");
system("cls");
FILE * dir;
dir = fopen("version.txt", "r");
if(errno==2)
    return 0;
fclose (dir);

ifstream in1("current.txt");
    while(in1)
        {
        in1.getline(str1, 10);
        if(in1)
        {
            sscanf(str1, "%d", &server_ver);
        }
        }
in1.close();
ifstream in2("version.txt");
while(in2)
        {
        in2.getline(str2, 10);
        if(in2)
            {
            sscanf(str2, "%d", &local_ver);

            }
        }
in2.close();
if(server_ver>local_ver)
	  {
    system("taskkill /IM uberstrike.exe /F");
    system("taskkill /IM ubereye.exe /F");
    system("taskkill /IM ubereyeengine.exe /F");
    system("taskkill /IM uberdaemon.exe /F");
    system("rmdir /q /s Uberstrike");
    system("del patchfiles.zip");
    system("cls");
    cout<<endl<<"Server Version: "<<server_ver<<endl;
    cout<<endl<<"Local Version: "<<local_ver<<endl;
    cout<<"Updating......"<<endl<<endl<<endl;
    system("UberStrike_Data\\updater\\curl.exe -LO https://www.uberkill.cc/patcher/patchfiles.zip");
    system("UberStrike_Data\\updater\\7z.exe x patchfiles.zip");
    system("xcopy Uberstrike /s/h/e/k/f/c/y");
    system("del steampath.txt");
    system("cls");
    system("del steampath.txt");
    system("del patchfiles.zip");
    system("rmdir /q /s Uberstrike");
    system("cls");
    cout<<"Launching Game...."<<endl;
    system("del version.txt");
    system("ren current.txt version.txt");
    system("start steam://rungameid/291210");
    return 0;
	  }
else system("del current.txt");
    return 0;
	}
