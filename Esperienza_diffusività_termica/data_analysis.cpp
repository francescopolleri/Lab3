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
TCanvas* c1=new TCanvas("c1","",600,600);
c1->Divide(2,1);
ifstream file("file_1_1s.lvm");

TF1* f=new TF1("f","[0]/sqrt([1]*x)*exp(-[2])");

double t,tc,risc,pt;
const double c=41e-6;
TGraph* g1=new TGraph;
TGraph* g2=new TGraph;
TGraph* g3=new TGraph;

for(int i=0;file>>t>>tc>>risc>>pt;i++){
    if(t>0){
    g1->SetPoint(i,t,tc);
    //g2->SetPoint(i,1/t,log(tc));
    //g3->SetPoint(i,t,pt);
    }
}

c1->cd(1);
g1->Draw("ap");
//c1->cd(2);
//g2->Draw("ap");



app.Run(true);

return 0;
}