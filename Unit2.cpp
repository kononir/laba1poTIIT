//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
struct mn {int *M; int numberofel; int predst;} *s; //���������, ���������� ���������(������), ���������� ���-�� ��������� �� ��������� � ����������, ������ ������������� ������� ���������
int Make_Set(int x ,int nummn, int numelmax){ //������� �������� ������ ���������(�� ��������� ������������� - ������� ��������)
        int setnumber, c;
        setnumber=Find_Set(x, nummn);
        if(setnumber>=0){
                c=2;
                return c;
        }
        else{
                for(int i=0;i<nummn;i++){
                        if(s[i].numberofel==0){
                                s[i].M[0]=x; //������ ������������� � ���������
                                s[i].predst=x; //� � ���������
                                c=1;
                                s[i].numberofel=1; //���-�� ��������� ���������� ��������� ����� 1
                                return c;
                        }
                }
        }
}
int Add_Element(int x, int y, int nummn){ //������� ���������� ���������� � ��� ���������� ��������� � ������������ ������ ��������� - ��������������
        int q, c, l;
        q=Find_Set(x, nummn); //����� ��������� � �������� ��������������
        if(q>=0){ //���� ������������� ������
                l=Find_Set(y, nummn);
                if(l<0){ //���� ���� ������� �� ����� �� ������ �������� ��������
                        c=1;
                        s[q].M[s[q].numberofel]=y; //����� ���������� ����� � ���������, ���� �� ����� ����������, ����������� �������� ������� � ���������
                        s[q].numberofel=s[q].numberofel+1; //����������� ���-�� ��������� ��������� �� �������� ���-��
                        return c;
                }
                else{ //���� ���� ���������� ���������
                        c=3;
                        return c;
                }
        }
        else{ //���� �� ������ �������������
                c=2;
                return c;
        }
}
int Union(int x, int y, int nummn, int numelmax, int nummnforunion){ //������� ����������� ���� �������� �� �������� ��������� ���� ��������
        int c, nomer1, nomer2, nomer3;
        if(nummn<3){
                c=4;
                return c;
        }
        nomer1=Find_Set(x, nummn);
        nomer2=Find_Set(y, nummn);
        if(nomer1<0||nomer2<0){
                c=2;
                return c; //���� �������(�) �� ������(�), �� ������� ������;
        }
        else{
                if(nomer1==nomer2) c=3; //���� �������� ������� � �����, �� ������� ���������� �� ����
                else{ //���� �������� ��������
                        for(int i=nummnforunion;i<nummn;i++){ //���� � ������� ������������� ��������� ��� �����������(������� � ���������, ������� ��������� ���-�� ��������� ��������)
                                if(s[i].numberofel==0){
                                        nomer3=i;
                                        break;
                                }
                                else continue;
                        }
                        c=1;
                        s[nomer3].numberofel=s[nomer1].numberofel+s[nomer2].numberofel; //� ��� ��������� ���������� �������� ���-�� ��-��
                        delete s[nomer3].M;
                        s[nomer3].M=new int[s[nomer3].numberofel]; //������ ������������ ������ ���������, � ������� � ��������� �������� ��� ������ ��������
                        s[nomer3].predst=s[nomer1].predst; //�������������, ������� ������������� ������� ���������
                        for(int i=0;i<s[nomer1].numberofel;i++) s[nomer3].M[i]=s[nomer1].M[i]; //�������� ������� ���������
                        for(int i=s[nomer1].numberofel, j=0 ; i<s[nomer1].numberofel+s[nomer2].numberofel && j<s[nomer2].numberofel ; i++, j++) s[nomer3].M[i]=s[nomer2].M[j]; //�������� ������� ���������, ������� ����� ����� ��������� ��������� ������� ���������
                        delete s[nomer1].M;                   //
                        s[nomer1].M=new int[numelmax];       //
                        s[nomer1].numberofel=0;             //
                        delete s[nomer2].M;                //"�������" �������� ��������� ��� ����������� �������������
                        s[nomer2].M=new int[numelmax];    //
                        s[nomer2].numberofel=0;          //
                }

        }
        return c;
}
int Find_Set(int x, int nummn){ //������� ������ ��������� �� ��������� ��-��
        int c;
        for(int i=0;i<nummn;i++){
                for(int j=0;j<s[i].numberofel;j++){
                        if(x==s[i].M[j]&&s[i].numberofel>0){
                                c=i;
                                return c;
                        }
                }
        }
        c=-1;
        return c;
}
int All_Sets(int nummn){
        int c, time=0;
        for(int i=0;i<nummn;i++){
                if(s[i].numberofel>0){
                        c=1;
                        time=time+1;
                        continue;
                }
        }
        if(time==0){
                c=2;
                return c;
        }
        for(int i=0;i<nummn;i++){
                if(s[i].numberofel>0){
                        cout<<"\npredstavitel="<<s[i].predst<<"\telementy:{";
                        for(int j=0;j<s[i].numberofel;j++){
                                if(j==s[i].numberofel-1){
                                        cout<<s[i].M[j];
                                        break;
                                }
                                cout<<s[i].M[j]<<",";
                        }
                        cout<<"}"<<endl;
                }
        }
        return c;
}
int Certain_Set(int x, int nummn){
        int c;
        for(int i=0;i<nummn;i++){
                if(s[i].numberofel>0 && s[i].predst==x){
                        c=1;
                        cout<<"\npredstavitel="<<s[i].predst<<"\telementy:{";
                        for(int j=0;j<s[i].numberofel;j++){
                                if(j==s[i].numberofel-1){
                                        cout<<s[i].M[j];
                                        break;
                                }
                                cout<<s[i].M[j]<<",";
                        }
                        cout<<"}"<<endl;
                        break;
                }
                else c=2;
        }
        return c;
}
int Find_Set_Predst(int x, int nummn){ //������� ������ ��������� �� ��������� ��-��
        int c;
        for(int i=0;i<nummn;i++){
                for(int j=0;j<s[i].numberofel;j++){
                        if(x==s[i].M[j]&&s[i].numberofel>0){
                                c=s[i].predst;
                                return c;
                        }
                }
        }
}
void Structure(int nummn, int numelmax){
        s=new mn[nummn];
        for(int i=0;i<nummn;i++){
                s[i].M=new int[numelmax];
                s[i].numberofel=0; //������������� ������������� ��������
        }
}
