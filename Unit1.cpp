//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <conio.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#include "Unit2.h"
#pragma argsused
int x, z, y, nummn, numelmax=100;
char answer;
int main(int argc, char* argv[])
{
cout<<"vvedite max kolichestvo mnozestv"<<endl;
cin>>nummn;
Structure(nummn);
//ini();
int number;
while(1){
        cout<<endl<<"1-new set\n2-add elements\n3-union\n4-find set\n5-show sets\n0-exit"<<endl;
        cin>>number;
        switch(number){
                case 1: //�������� ������ ���������
                       cout<<endl<<"max kolichestvo mnozestv="<<nummn<<endl;
                       M:
                       if(nummn==0){
                                cout<<endl<<"limit mnozestv!"<<endl;
                                break;
                       }
                       else{
                                cout<<endl<<"vvedite predstavitela"<<endl;
                                cin>>x;
                                z=Make_Set(x ,nummn, numelmax);
                                if(z==2){
                                        cout<<endl<<"False input"<<endl<<"Try again?(y/n)"<<endl;
                                        cin>>answer;
                                        if(answer=='y') goto M;
                                        if(answer=='n') break;
                                }
                                else{
                                        nummn=nummn-1;
                                        cout<<endl<<"Successfull!"<<endl<<"Would you like to add elements?(y/n)"<<endl;
                                        cin>>answer;
                                        if(answer=='y') goto L;
                                        if(answer=='n') break;
                                }
                       }
                break;
                case 2:
                       L:
                       cout<<endl<<"vvedite predstavitela mnozestva i vnosimiy element"<<endl;
                       cin>>x>>y;
                       z=Add_Element(x, y, nummn, numelmax);
                       if(z==1){
                                cout<<endl<<"Successfull! Would you like to add another element?(y/n)"<<endl;
                                cin>>answer;
                                if(answer=='y') goto L;
                                if(answer=='n') break;
                       }
                       if(z==2){
                                cout<<endl<<"False input. Would you like to try other predstavitel?(y/n)";
                                cin>>answer;
                                if(answer=='n') break;
                                if(answer=='y') goto L;
                       }
                       if(z==3){
                                cout<<endl<<"Wrong input(this element is already exist). Would you like to try other element?(y/n)";
                                cin>>answer;
                                if(answer=='n') break;
                                if(answer=='y') goto L;
                       }
                break;
                case 3:
                       cout<<endl<<"vvedite po odnomy elementy dvyx mnozestv"<<endl;
                       cin>>x>>y;
                       z=Union(x, y, nummn, numelmax);
                       if(z==1) cout<<endl<<"Successfull!"<<endl;
                       if(z==2) cout<<endl<<"False input"<<endl;
                       if(z==3) cout<<endl<<"Vvedeny elementy odnogo mnozestva"<<endl;
                break;
                case 4:
                       int z1, z2;
                       cout<<endl<<"vvedite element mnozestva"<<endl;
                       cin>>x;
                       z1=Find_Set(x, numelmax, nummn);
                       if(z1<0){
                                cout<<endl<<"False input!"<<endl;
                                break;
                       }
                       else{
                                z2=Find_Set_Predst(x, nummn, numelmax);
                                cout<<endl<<"etot element-element mnozestva s predstvitelem: "<<z2<<endl;
                       }
                break;
                case 5:
                       cout<<endl<<"What do you want to see?(1-all sets 2-certain set)"<<endl;
                       cin>>answer;
                       if(answer=='1'){
                                z=All_Sets(nummn);
                                if(z==2) cout<<"There are no sets!"<<endl;
                       }
                       if(answer=='2'){
                                cout<<endl<<"vvedite predstavitela mnozestva"<<endl;
                                cin>>x;
                                z=Certain_Set(x, nummn);
                                if(z==2) cout<<"There is no such set!"<<endl;
                       }
                break;
                default:
                        return 0;
        }
}
getch();
}
//---------------------------------------------------------------------------














