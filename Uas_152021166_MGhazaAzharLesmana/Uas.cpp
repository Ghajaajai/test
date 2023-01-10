#include<iostream>
#include<cmath>
using namespace std;

//Nama : Muhammad Ghaza Azhar Lesmana
//Kelas : DD
//Nim : 152021166

struct grupxy {
    float x;
    float y;
    float xy;
    float x2;
    float y2;
};
grupxy xy_input[50];
void inputxy(int byk);

int main(){
    int n;
    float sigma_x, sigma_y, sigmax2, sigmay2, sigma_xy;   
    float hasil_sigmax2, hasil_sigmay2, baganatas, baganbawah;
    float akarx, akary, prsx, prsy, r;

   //variabel di bawah dideklarasikan dengan nilai 0
    sigma_x = 0; sigma_y = 0; sigma_xy = 0; sigmax2 = 0; sigmay2 = 0;    
    hasil_sigmax2 = 0; hasil_sigmay2 = 0; baganatas =0; baganbawah=0; akarx=0; akary=0;
    prsx =0; prsy = 0; r = 0;
  
  //menginput banyak data
    cout << "Masukan banyak data yang ingin diinput: ";cin >> n;

  //menginput data x dan y
 for(int i = 1; i<=n;i++){
    cout << "Input x ke-" << i << " : ";cin >> xy_input[i].x;
    cout << "Input y ke-" << i << " : ";cin >> xy_input[i].y;
    cout << endl << "-----------------------------------------------" << endl; 
   
    }

    cout << endl << "//// Hasil dari sigma x, sigma y, dan sigma_xy ////" << endl;
    //sigma x, y, xy
    for(int i = 1; i <= n; i++){
        sigma_x = xy_input[i].x + sigma_x;
        sigma_y = xy_input[i].y + sigma_y;
        xy_input[i].xy= xy_input[i].x * xy_input[i].y;
        sigma_xy += xy_input[i].xy;
    }
   cout << "hasil sigma x adalah : " << sigma_x << endl ;
   cout  << "hasil sigma y adalah : " << sigma_y << endl;
   cout  << "hasil sigma xy adalah : " << sigma_xy << endl;

  //Operasi Sigma XY 
    cout << endl;
    cout << "Operasi bagian atas" << endl;
    baganatas = sigma_xy - (sigma_x*sigma_y);
    cout << baganatas << endl;
    cout << endl;
    cout << "//// Hasil sigma x kuadrat dan Hasil sigma y kuadrat ////" << endl;
    for(int i =1; i <=n; i++) {
     xy_input[i].x2 = xy_input[i].x * xy_input[i].x;
     sigmax2 += xy_input[i].x2;
    xy_input[i].y2 = xy_input[i].y * xy_input[i].y;
     sigmay2 += xy_input[i].y2;}

   //sigma x kuadrat
    hasil_sigmax2 = sigma_x * sigma_x;
   //sigma y kuadrat
    hasil_sigmay2 = sigma_y * sigma_y;
  
    prsx = sigmax2 - hasil_sigmax2;
    prsy = sigmay2 - hasil_sigmay2;
    akarx = sqrt(prsx);
    akary = sqrt(prsy);
  
    //Output sigam x kuadrat, y kuadrat, dan hasil jumlah sigam x kuadrat, y kuadrat
    cout << "Hasil sigma x kuadrat adalah : " << sigmax2 << endl;
    cout << "hasil sigma y kuadrat adalah : " << sigmay2 << endl;
    cout << "hasil jumlah sigma x kuadrat adalah : " << hasil_sigmax2 << endl;
    cout << "hasil jumlah sigma y kuadrat  adalah : " << hasil_sigmay2 << endl;

    //Operasi Sigma X dan Sigma Y 
    cout << endl;
    cout << "Operasi bagian Bawah" << endl;
    cout << baganbawah ;
     baganbawah = akarx * akary;

   //Operasi dan hasil r
     r = baganatas / baganbawah;
     cout << "Hasil r"  << endl; 
     cout << "r = " << r << endl;

  //Operasi dan hasil Koefisien Determinasi r
  cout << endl;
  float koef_determinasi_r = r * r * 100 /100;
  cout << "hasil Koefisien Determinasi R = " << koef_determinasi_r << endl;

  //Hubungan korelasi
     cout << endl << "Kekuatan hubungan antara nilai Korelasi adalah : " ;
      
      if (r>0 && r<=0.09){
        cout << "Hubungan korelasi antara nilai korelasi adalah diabaikan " << endl;
        } 
         else if (r>=0.1 && r<=0.29){
          cout << "Hubungan korelasi antara nilai korelasi adalah sangat rendah " << endl;
        }
       
          else if (r>=0.3 && r<=0.49){
          cout << "Hubungan korelasi antara nilai korelasi adalah sangat moderat " << endl;
        }
            else if (r>=0.5 && r<=0.7){
         cout << "Hubungan korelasi antara nilai korelasi adalah sangat sedang " << endl; 
        }
         else if (r >0.7){
           cout << "Hubungan korelasi antara nilai korelasi adalah sangat kuat " << endl;
        }
       
    cout << "--------------------------";
    if(r> 0) {
      cout << "Hubungan antara variabel x dan y adalah positif, dimana jika nilai x bertambah, maka nilai y pun bertambah, dan juga sebaliknya" << endl;
      }
    
    else if(r<0){
      cout << "Hubungan antara variabel x dan y adalah negatif, dimana jika nilai x betambah, maka nilai y akan mengecil, dan juga sebaliknya" << endl;
      }
    else if(r==0){
      cout << "Tidak Ada Hubungan antara antara variabel x dan y" << endl; 
      }
  
  return 0;
}
