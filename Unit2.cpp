//---------------------------------------------------------------------------
#include <vcl.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
struct mn {int M[100]; int numberofel; int predst;} *s; //���������, ���������� ���������(������), ���������� ���-�� ��������� �� ��������� � ����������, ������ ������������� ������� ���������
int a=100, b, x, y;
int Make_Set(int x ,int nummn, int numelmax){ //������� �������� ������ ���������(�� ��������� ������������� - ������� ��������)
        int setnumber, c;
        setnumber=Find_Set(x, numelmax, nummn);
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
int Add_Element(int x, int y, int nummn, int numelmax){ //������� ���������� ���������� � ��� ���������� ��������� � ������������ ������ ��������� - ��������������
        int q, c;
        for(int i=0;i<nummn;i++){ //����� ��������� � �������� ��������������
                if(x==s[i].predst && s[i].numberofel>0){
                        if(s[i].numberofel==a){
                                c=3;
                                return c;
                        }
                        for(int k=0;k<nummn;k++){ //�������� �������� �� ������������� � ������ ����������
                                for(int l=0;l<numelmax;l++){
                                        if(y!=s[k].M[l]){ //���� �� ����� �������� ���������
                                                c=1;
                                                continue; //�� ���������� ���� �� ������� ����������
                                        }
                                        else{
                                                c=3;
                                                return c;
                                        }
                                }
                        }
                        s[i].M[s[i].numberofel]=y; //����� ���������� ����� � ���������, ���� �� ����� ����������, ����������� �������� ������� � ���������
                        s[i].numberofel=s[i].numberofel+1; //����������� ���-�� ��������� ��������� �� �������� ���-��
                }
                else{
                        c=2;
                        continue;
                }
                break;
        }
        return c;
}
int Union(int x, int y, int nummn, int numelmax){ //������� ����������� ���� �������� �� �������� ��������� ���� ��������
        int c, nomer1, nomer2, nomer3;
        nomer1=Find_Set(x, numelmax, nummn);
        nomer2=Find_Set(y, numelmax, nummn);
        if(nomer1<0||nomer2<0||(nomer1+nomer2)>numelmax) c=2; //���� �������(�) �� ������(�) (��� �� ����� ���������� ��������� ������������ ���������� ���������), �� ������� ������;
        else{
                if(nomer1==nomer2) c=3; //���� �������� ������� � �����, �� ������� ���������� �� ����
                else{ //���� �������� ��������
                        for(int i=0;i<nummn;i++){ //���� � ������� ������������� ���������
                                if(s[i].numberofel==0){
                                        nomer3=i;
                                        break;
                                }
                                else continue;
                        }
                        c=1;
                        s[nomer3].numberofel=s[nomer1].numberofel+s[nomer2].numberofel; //� ��� ��������� ���������� �������� ���-�� ��-��
                        s[nomer3].predst=s[nomer1].predst; //�������������, ������� ������������� ������� ���������
                        for(int i=0;i<s[nomer1].numberofel;i++) s[nomer3].M[i]=s[nomer1].M[i]; //�������� ������� ���������
                        for(int i=s[nomer1].numberofel, j=0 ; i<s[nomer1].numberofel+s[nomer2].numberofel && j<s[nomer2].numberofel ; i++, j++) s[nomer3].M[i]=s[nomer2].M[j]; //�������� ������� ���������, ������� ����� ����� ��������� ��������� ������� ���������
                        s[nomer2].numberofel=s[nomer1].numberofel=-1; //"�������" �������� ��������� �� ���������, ������� �� �� ������� ������
                }

        }
        return c;
}
int Find_Set(int x, int numelmax, int nummn){ //������� ������ ��������� �� ��������� ��-��
        int c;
        for(int i=0;i<nummn;i++){
                for(int j=0;j<numelmax;j++){
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
        int c;
        for(int i=0;i<nummn;i++){
                if(s[i].numberofel>0){
                        c=1;
                        break;
                }
                else{
                        c=2;
                        return c;
                }
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
                if(s[i].numberofel>0&&s[i].predst==x){
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
//void ini(void){
//        for(int i=0;i<b;i++){
//                s[i].numberofel=0; //������������� ������������� ��������
//        }
//}
int Find_Set_Predst(int x, int nummn, int numelmax){ //������� ������ ��������� �� ��������� ��-��
        int c;
        for(int i=0;i<nummn;i++){
                for(int j=0;j<numelmax;j++){
                        if(x==s[i].M[j]&&s[i].numberofel>0){
                                c=s[i].predst;
                                return c;
                        }
                }
        }
        return c;
}
int Structure(int nummn){
        s=new mn[nummn];
        return nummn;
}