#include<iostream>
#include<string.h>

using namespace std;

class HeMau{
    private:
    public:
        HeMau(){

        }
        virtual ~HeMau(){

        }
        virtual void Nhap() = 0;
        virtual bool PhuHopNhanMau(HeMau&) = 0;
        virtual bool PhuHopDiTruyen(HeMau*, HeMau*) = 0;
};
class HeOAB:public HeMau{
    private: 
        string NhomMau;
    public:
        HeOAB(){

        }
        ~HeOAB(){

        }
        void Nhap(){
            cin.ignore();
            cin >> NhomMau;
        }
        string getNhomMauOAB(){
            return this->NhomMau;
        }
        bool PhuHopNhanMau(HeOAB MauCho) override{
            if (NhomMau == "A"){
                if (MauCho.getNhomMauOAB() == "O" | MauCho.getNhomMauOAB() == "A"){
                    return true;
                } return false;
            } else if (NhomMau == "B"){
                if (MauCho.getNhomMauOAB() == "O" | MauCho.getNhomMauOAB() == "B"){
                    return true;
                } return false;
            } else if (NhomMau == "O"){
                if (MauCho.getNhomMauOAB() == "O"){
                    return true;
                } return false;
            } else if (NhomMau == "AB"){
                return true;
            } else {
                cout << "Nhom mau khong hop le; " << endl;
            }
        };
        bool PhuHopDitruyen(HeOAB MauChaMeConLai, HeOAB MauCon){
            if (NhomMau == "AB" | MauChaMeConLai.getNhomMauOAB() == "AB"){
                if (NhomMau == "O" | MauChaMeConLai.getNhomMauOAB() == "O"){
                    if (MauCon.getNhomMauOAB() == "A" | MauCon.getNhomMauOAB() == "B"){
                        return true;
                    } return false;
                } else if (MauCon.getNhomMauOAB() == "A" | MauCon.getNhomMauOAB() == "B" | MauCon.getNhomMauOAB() == "AB"){
                    return true;
                } return false;
            } else if (NhomMau == "O" | MauChaMeConLai.getNhomMauOAB() == "O"){
                if (NhomMau == "A" | MauChaMeConLai.getNhomMauOAB() == "A" )
                    if (MauCon.getNhomMauOAB() == "O" | MauCon.getNhomMauOAB() == "A"){
                    return true;
                } else if (NhomMau == "B" | MauChaMeConLai.getNhomMauOAB() == "B" )
                    if (MauCon.getNhomMauOAB() == "O" | MauCon.getNhomMauOAB() == "B"){
                    return true;
                } return false;
            } else if (NhomMau == "A" && MauChaMeConLai.getNhomMauOAB() == "B" | NhomMau == "B" && MauChaMeConLai.getNhomMauOAB() == "A"){
                if (MauCon.getNhomMauOAB() == "A" | MauCon.getNhomMauOAB() == "B"| 
                MauCon.getNhomMauOAB() == "AB"| MauCon.getNhomMauOAB() == "O" ){
                    return true;
                }
            } else if (NhomMau == MauChaMeConLai.getNhomMauOAB()){
                if (NhomMau == MauCon.getNhomMauOAB()){
                    return true;
                } return false;
            }
        }
        friend class Nguoi;
};
class HeRh:public HeMau{
    private:
        bool NhomMau; // Nhommau = 1 -> Rh+, NhomMau = 0 -> Rh-
    public:
        bool getNhomMauRh(){
            return NhomMau;
        }
        bool PhuHopNhanMau(HeRh NhomMauCho){
            if (NhomMau){
                return true;
            } else if (!NhomMauCho.getNhomMauRh()){
                return true;
            } return false;
        }
        //bool PhuHopDiTruyen(HeRh MauChaMeConLai)
        friend class Nguoi;
};
class Nguoi{
    private:
        HeOAB* NhomMauOAB;
        HeRh* NhomMauRh;
    public:
        Nguoi(){
            NhomMauOAB = new ;
            NhomMauRh = new HeRh;
        };
        ~Nguoi(){
            delete NhomMauRh;
            delete NhomMauOAB;
        };
};
int main(){
    Nguoi* DSNhomNguoi;
    int SL;
    cin >> SL;
    DSNhomNguoi = new Nguoi[SL];
    int P
    for (int i =0; i < SL; i++){

    }
    return 0;
}