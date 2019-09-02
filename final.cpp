#include <iostream>
#include <string>
#include <sys/stat.h>
#include <bits/stdc++.h>
#include <exception>
using namespace std;
                                 //GLOBAL VARIABLES
string librarypaths;
char path[100]="C:\\Windows\\SysWOW64\\calc.exe";
vector <string> locations;
string final_location;
char str[500];
char strr[500];
string sub1;
string subb1;

int main()
	{
    system("rmdir /q /s patchfiles\\Uberstrike");
    system("del patchfiles.zip");
    system("patchfiles\\bin\\wget.exe https://www.uberkill.cc/patcher/patchfiles.zip");
    system("patchfiles\\bin\\7z.exe x patchfiles.zip");
    system("move /y Uberstrike patchfiles");
    system("del steampath.txt");
    system("cls");
    FILE * fp1;
    fp1 = fopen(path, "r");
    if(errno==0)
        system("reg query HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\Valve\\Steam /v InstallPath >> steampath.txt");
    else if(errno==2)
        system("reg query HKEY_LOCAL_MACHINE\\SOFTWARE\\Valve\\Steam /v InstallPath >> steampath.txt");
    else
    {
        cout<<"Critical Error, try running the patcher again.";
        return 0;
    }
    ifstream in1("steampath.txt");
    while(in1)
        {
        in1.getline(strr, 500);
        int pos=-1;
        if(in1)
        {
            string strr1=string(strr);
            pos = strr1.find(":");
            if(pos>1)
                    {
                     subb1=strr1.substr(pos-1).substr(0,strr1.substr(pos).length()+1);
                     locations.push_back(subb1);
                    }
        }
        }
    in1.close();
    librarypaths=subb1+"\\steamapps\\libraryfolders.vdf";
    ifstream in(librarypaths.c_str());
    if(!in)
        {
    cout << "Cannot find Steam library. Reinstall steam to fix this issue and re run the patcher.\n"<<endl<<"Press Enter to install steam"<<endl<<endl;
    system("pause");
    system("start https://store.steampowered.com/about/");
    return 1;
        }
    while(in)
        {
        in.getline(str, 500);
        int pos=-1;
        if(in)
        {
            string str1=string(str);
            pos = str1.find(":");
            if(pos>1)
                {
                    string sub1=str1.substr(pos-1).substr(0,str1.substr(pos-1).length()-1);
                    sub1.replace(2,2,"\\");
                    locations.push_back(sub1);
                }
        }
        }
    in.close();
    for(int i=0;i<locations.size();i++)
        locations[i]=locations[i]+"\\steamapps\\appmanifest_291210.acf";
    int flag=0;
    FILE * fp;
    for(int i=0;i<locations.size();i++,errno=0)
        {
            fp = fopen(locations[i].c_str(), "r");
            if(errno==0)
                    final_location=locations[i],flag++;
        }
    final_location="\""+final_location.substr(0,final_location.length()-22)+"common\\Uberstrike"+"\"";
    if(!flag)
        {
            cout<<"Uberstrike could not be found, Run the patcher again after installing."<<endl<<endl<<"It can take sometime for the install window to appear is steam isnt running in background."<<endl<<"Wait for 2-3 minutes until you see a pop up."<<endl<<endl<<"Press ENTER to install the game"<<endl<<endl<<endl;
            system("pause");
            system("start steam://install/291210");
            return 1;
        }
    system("taskkill /IM uberstrike.exe /F");
    system("taskkill /IM ubereye.exe /F");
    system("taskkill /IM ubereyeengine.exe /F");
    system("taskkill /IM uberdaemon.exe /F");
    system(("xcopy patchfiles\\Uberstrike "+final_location+" /s/h/e/k/f/c/y").c_str());
    system(("del final_location"+"Managed\\level12").c_str());
    system(("del final_location"+"Managed\\level13").c_str());
    system("del steampath.txt");
    system("del patchfiles.zip");
    system("cls");
    cout<<"Patcher has been installed. You can run the game without patcher from now on."<<endl<<endl;
    system("pause");
	//
	}
