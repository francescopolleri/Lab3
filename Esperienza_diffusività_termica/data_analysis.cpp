#include <cmath>
#include <fstream>
#include <vector>
#include<functional>
#include<iostream>

#include <TGraph.h>
#include <TGraphErrors.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TH2D.h>
#include <TApplication.h>
#include <TStyle.h>
#include <TLegend.h>

using namespace std;

int main(){
TApplication app("app",0,NULL);

ifstream file1("file_1_1s.lvm");
double t1,tc1,risc1,pt1;
vector<double> T1,TC1;

ifstream file2("file_2_1s.txt");
double t2,tc2,risc2,pt2;
vector<double> T2,TC2;

ifstream file3("file_3_1s.txt");
double t3,tc3,risc3,pt3;
vector<double> T3,TC3;

ifstream file4("file_4_0.5s.txt");
double t4,tc4,risc4,pt4;
vector<double> T4,TC4;

ifstream file5("file_5_1.5s.txt");
double t5,tc5,risc5,pt5;
vector<double> T5,TC5;

TGraphErrors g1,g2,g3,g4,g5;
TGraphErrors G1,G2,G3,G4,G5;
TH1D h("h","",30,0,0);

double G=2000;
double c=41e-6;

int i1=0;
while(file1>>t1>>tc1>>risc1>>pt1){
    if(t1==0){
        continue;
    }
    G1.SetPoint(i1,t1,-tc1/(G*c));
    G1.SetPointError(i1,0,0.02);
    g1.SetPoint(i1,1/t1,log(sqrt(t1)*tc1/(G*c)));
    g1.SetPointError(i1,0,0.02*G*c/(sqrt(t1)*tc1));
    i1++;
}
int i2=0;
while(file2>>t2>>tc2>>risc2>>pt2){
    if(t2==0){
        continue;
    }
    G2.SetPoint(i2,t2,-tc2/(G*c));
    G2.SetPointError(i2,0,0.02);
    g2.SetPoint(i2,1/t2,log(sqrt(t2)*tc2/(G*c)));
    g2.SetPointError(i2,0,0.02*G*c/(sqrt(t2)*tc2));
    i2++;
}
int i3=0;
while(file3>>t3>>tc3>>risc3>>pt3){
    if(t3==0){
        continue;
    }
    G3.SetPoint(i3,t3,-tc3/(G*c));
    G3.SetPointError(i3,0,0.02);
    g3.SetPoint(i3,1/t3,log(sqrt(t3)*tc3/(G*c)));
    g3.SetPointError(i3,0,0.02*G*c/(sqrt(t3)*tc3));
    i3++;
}
int i4=0;
while(file4>>t4>>tc4>>risc4>>pt4){
    if(t4==0){
        continue;
    }
    G4.SetPoint(i4,t4,-tc4/(G*c));
    G4.SetPointError(i4,0,0.02);
    g4.SetPoint(i4,1/t4,log(sqrt(t4)*tc4/(G*c)));
    g4.SetPointError(i4,0,0.02*G*c/(sqrt(t4)*tc4));
    i4++;
}
int i5=0;
while(file5>>t5>>tc5>>risc5>>pt5){
    if(t5==0){
        continue;
    }
    G5.SetPoint(i5,t5,-tc5/(G*c));
    G5.SetPointError(i5,0,0.02);
    g5.SetPoint(i5,1/t5,log(sqrt(t5)*tc5/(G*c)));
    g5.SetPointError(i5,0,0.02*G*c/(sqrt(t5)*tc5));
    i5++;
}

TCanvas c1("c1","",700,700);
c1.cd();
G1.SetLineColor(6);
G2.SetLineColor(3);
G3.SetLineColor(4);
G4.SetLineColor(5);
G1.SetLineColor(2);
G1.Draw();
G2.Draw("same");
G3.Draw("same");
G4.Draw("same");
G5.Draw("same");

TCanvas c2("c1","",700,700);
c2.cd();
g1.SetLineColor(6);
g2.SetLineColor(3);
g3.SetLineColor(4);
g4.SetLineColor(5);
g1.SetLineColor(2);
g1.Draw();
g2.Draw("same");
g3.Draw("same");
g4.Draw("same");
g5.Draw("same");

TF1 f("f","[0]+[1]*x");

g1.Fit("f","","",3,10);
cout<<"fit1 done"<<endl;
g2.Fit("f","","",3,10);
cout<<"fit2 done"<<endl;
g3.Fit("f","","",3,10);
cout<<"fit3 done"<<endl;
g4.Fit("f","","",3,10);
cout<<"fit4 done"<<endl;
g5.Fit("f","","",3,10);
cout<<"fit5 done"<<endl;

app.Run(true);

return 0;
}