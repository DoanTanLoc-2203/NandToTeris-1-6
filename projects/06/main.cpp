#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdio>
#include <sstream>

using namespace std;

void decToBinary(int n,string &conv)
{
    int binaryNum[15];
    for(int i=0;i<15;i++)
    {
        binaryNum[i]=0;
    }
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = 14; j >= 0; j--)
    {
        if(binaryNum[j]==0)
        {
            conv+="0";
        }
        else
            conv+="1";
    }
}

int main(int argc, char **argv)
{
    ifstream ifs;
    fstream f;
	f.open("output.hack", ios::out);
	ifs.open("add/Add.asm");
    while (!ifs.eof())
    {
            bool check=false;
            bool checkspace=false;
            char temp[255];
            ifs.getline(temp, 255);
            for(int i=0;i<255;i++)
            {
                if(temp[i]=='/'&&temp[i+1]=='/')
                {
                    check=true;
                    break;
                }
            }
            for(int i=0;i<strlen(temp);i++)
            {
                if(temp[i]!=32)
                {
                    checkspace=true;
                    break;
                }
            }
            if(check==false&&checkspace==true)
            {
                string result="";
                string comp="";
                string des="";
                string jum="";
                bool checkdau=false;
                bool checkdau2=false;
                bool checkout=false;
                for(int i=0;i<strlen(temp);i++)
                {
                    if(temp[i]!=' ')
                    {
                        if(temp[i]=='@')
                        {
                            result+="0";
                            string num="";
                            for(int j=i+1;j<strlen(temp);j++)
                            {
                                if(temp[j]!=' ')
                                {
                                    num+=temp[j];
                                }
                                else break;
                            }
                            stringstream str2num(num);
                            int x = 0;
                            str2num >> x;
                            decToBinary(x,result);
                            checkout=true;
                            break;
                        }
                    }
                    char *s;
                    s=strchr(temp,'@');
                    if(s==NULL)
                    {
                        if(temp[i]=='=') checkdau=true;
                        if(temp[i]==';') checkdau2=true;
                        if(temp[i]!=' '&& checkdau==false)
                        {
                            des+=temp[i];
                        }
                        if(checkdau==true&&temp[i]!=' '&&checkdau2==false)
                        {
                            if(temp[i]!=' '&&temp[i]!='=')
                                comp+=temp[i];
                        }
                        if(checkdau2==true&&temp[i]!=' ')
                        {
                            if(temp[i]!=' '&&temp[i]!=';')
                                jum+=temp[i];
                        }
                    }
                }
                    if(checkout==false)
                    {
                        result+="111";
                        //result+="/";
                        if(comp=="0")
                            result+="0101010";
                        else if(comp=="1")
                            result+="0111111";
                        else if(comp=="-1")
                            result+="0001100";
                        else if(comp=="D")
                            result+="0001100";
                        else if(comp=="A")
                            result+="0110000";
                        else if(comp=="!D")
                            result+="0001101";
                        else if(comp=="!A")
                            result+="0110001";
                        else if(comp=="-D")
                            result+="0001111";
                        else if(comp=="-A")
                            result+="0110011";
                        else if(comp=="D+1")
                            result+="0011111";
                        else if(comp=="A+1")
                            result+="0110111";
                        else if(comp=="D-1")
                            result+="0001110";
                        else if(comp=="A-1")
                            result+="0110010";
                        else if(comp=="D+A")
                            result+="0000010";
                        else if(comp=="D-A")
                            result+="0010011";
                        else if(comp=="A-D")
                            result+="0000111";
                        else if(comp=="D&A")
                            result+="0000000";
                        else if(comp=="D|A")
                            result+="0010101";
                        else if(comp=="M")
                            result+="1110000";
                        else if(comp=="!M")
                            result+="1110001";
                        else if(comp=="-M")
                            result+="1110011";
                        else if(comp=="M+1")
                            result+="1110111";
                        else if(comp=="M-1")
                            result+="1110010";
                        else if(comp=="D+M")
                            result+="1000010";
                        else if(comp=="D-M")
                            result+="1010011";
                        else if(comp=="M-D")
                            result+="1000111";
                        else if(comp=="D&M")
                            result+="1000000";
                        else if(comp=="D|M")
                            result+="1010101";
                        /////////////////////////
                       // result+="/";
                        if(des=="null")
                            result+="000";
                        else if(des=="M")
                            result+="001";
                        else if(des=="D")
                            result+="010";
                        else if(des=="MD")
                            result+="011";
                        else if(des=="A")
                            result+="100";
                        else if(des=="AM")
                            result+="101";
                        else if(des=="aD")
                            result+="110";
                        else if(des=="AMD")
                            result+="111";
                        /////////////////////////////
                        //result+="/";
                        if(jum=="null")
                            result+="000";
                        else if(jum=="JGT")
                            result+="001";
                        else if(jum=="JEQ")
                            result+="010";
                        else if(jum=="JGE")
                            result+="011";
                        else if(jum=="JLT")
                            result+="100";
                        else if(jum=="JNE")
                            result+="101";
                        else if(jum=="JLE")
                            result+="110";
                        else if(jum=="JMP")
                            result+="111";
                        else
                            result+="000";
                       // cout<<des<<"="<<comp<<";"<<jum<<"\n";
                       cout<<result<<"\n";
                        f<<result<<"\n";
                    }
                    else
                        cout<<result<<"\n";
                         f<<result<<"\n";
            }
    }
    f.close();
    ifs.close();
	return 0;
}
