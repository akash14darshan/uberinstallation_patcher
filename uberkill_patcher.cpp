#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <io.h>
#include <sys/stat.h>
#include <bits/stdc++.h>
#if defined(_UNICODE)
#define _T(x) L ##x
#else
#define _T(x) x
#endif
#define BUFFER 8192
using namespace std;


	int isFileExists(const char *path);
int isFileExistsAccess(const char *path);
int isFileExistsStats(const char *path);
int locator(string locate);
int windowsbit64;
char steampath[500];
string steampaths;
string gamepaths;
string librarypaths;
char gamepath[500];
DWORD BufferSize = BUFFER;
char path[100]="C:\\Windows\\SysWOW64";
vector <string> locations;
string finallocation;


int main()
	{
        { //first chain
    if (isFileExistsAccess(path))
        windowsbit64=1;
    else
        windowsbit64=0;
	    }
        {

	    if(windowsbit64==0)
            RegGetValue(HKEY_LOCAL_MACHINE, "HKEY_LOCAL_MACHINE\\SOFTWARE\\Valve\\Steam", "InstallPath", RRF_RT_ANY, NULL, (PVOID)&steampath, &BufferSize);



        else if(windowsbit64==1)
            RegGetValue(HKEY_LOCAL_MACHINE, "SOFTWARE\\WOW6432Node\\Valve\\Steam", "InstallPath", RRF_RT_ANY, NULL, (PVOID)&steampath, &BufferSize);
        steampaths=string(steampath);
        locations.push_back(steampath);


        }

	    librarypaths=steampaths+"\\steamapps\\libraryfolders.vdf";

            ifstream in(librarypaths.c_str());
    if(!in) {
    cout << "Cannot open input file.\n";
    return 1;
  }
char str[500];
while(in)
    {
    in.getline(str, 500);
    int pos=-1;
    int count=0;
    if(in)
        {
           string str1=string(str);
            pos = str1.find(":");
            if(pos>1)
                {
            string sub = str1.substr(pos-1);
            string sub1=sub.substr(0,sub.length()-1);
            locations.push_back(sub1);

        }
        }
  }
  in.close();


for(int i=0;i<locations.size();i++)
    {finallocation=locations[i]+"\\steamapps\\appmanifest_291210.acf";
     cout<<finallocation<<endl;
    }

 //The string in which existence of uberstrike installation has to be checked
int count=0;
int flag=1;
    	while(count<10)
    {
        for(int i=0;i<10;i++)
        {
    cout<<"loop";
    FILE * fp;
    fp = fopen(finallocation.c_str(), "r");
    printf(" Value of errno: %d\n ", errno);
    cout<<endl;
    count=count+1;
        }
    }
if(!flag) cout<<"Not found";


	}

int isFileExists(const char *path)
{
    FILE *fptr = fopen(path, "r");
    if (fptr == NULL)
        return 0;
    fclose(fptr);
    return 1;
}
int isFileExistsAccess(const char *path)
{
    if (access(path, F_OK) == -1)
        return 0;
    return 1;
}
int isFileExistsStats(const char *path)
{
    struct stat stats;
    stat(path, &stats);
    if (stats.st_mode & F_OK)
        return 1;
    return 0;
}


