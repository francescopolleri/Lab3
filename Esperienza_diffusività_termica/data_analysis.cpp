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

ifstream file5("file_1_1.5s.txt");
double t5,tc5,risc5,pt5;
vector<double> T5,TC5;

TGraphErrors g1,g2,g3,g4,g5;
TH1D h("h","",30,0,0);

double G=2000;
double c=41e-6;

int i1=0;
while(file1>>t1>>tc1>>risc1>>pt1){
    if(t1==0){
        continue;
    }
    g1.SetPoint(i1,1/t1,log(sqrt(t1)*tc1/(G*c)));
    if(t1>115){
        h.Fill(tc1/(G*c));
    }
    i1++;
}
int i2=0;
while(file2>>t2>>tc2>>risc2>>pt2){
    if(t2==0){
        continue;
    }
    g2.SetPoint(i2,1/t2,log(sqrt(t2)*tc2/(G*c)));
    i2++;
}
int i3=0;
while(file3>>t3>>tc3>>risc3>>pt3){
    if(t3==0){
        continue;
    }
    g3.SetPoint(i3,1/t3,log(sqrt(t3)*tc3/(G*c)));
    i3++;
}
int i4=0;
while(file4>>t4>>tc4>>risc4>>pt4){
    if(t4==0){
        continue;
    }
    g4.SetPoint(i4,1/t4,log(sqrt(t4)*tc4/(G*c)));
    i4++;
}
int i5=0;
while(file5>>t5>>tc5>>risc5>>pt5){
    if(t5==0){
        continue;
    }
    g5.SetPoint(i5,1/t5,log(sqrt(t5)*tc5/(G*c)));
    i5++;
}

g1.Draw("ap");
g2.Draw("same");
g3.Draw("same");
g4.Draw("same");
g5.Draw("same");

TF1 f("f","[0]+[1]*x");

g1.Fit("f","","",5,10);
g2.Fit("f","","",5,10);
g3.Fit("f","","",5,10);
g4.Fit("f","","",5,10);
g5.Fit("f","","",5,10);

h.Draw();
app.Run(true);

return 0;
}