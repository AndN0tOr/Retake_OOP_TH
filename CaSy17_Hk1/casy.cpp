#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class CaSy{
private:
    string HoTen;
    int SoNamLamViec;
    int SoDiaBanRa;
    int SoBuoiTrinhDien;
public:
    CaSy(){
    };
    ~CaSy(){
    };
    virtual void Nhap(){
        cin.ignore();
        cout << "Nhap Ho ten Ca Sy: ";
        getline(cin, HoTen);
        cout << "Nhap so nam lam viec: ";
        cin >> SoNamLamViec;
        cout << "Nhap so dia ban ra: ";
        cin >> SoDiaBanRa;
        cout << "Nhap so buoi trinh dien: ";
        cin >> SoBuoiTrinhDien;
    }
    virtual void Xuat(){
        cout << "Ho Ten: " << HoTen << endl;
        cout << "So Nam Lam viec: " << SoNamLamViec << endl;
        cout << "So Dia ban ra: " << SoDiaBanRa << endl;
        cout << "So Buoi trinh dien" << SoBuoiTrinhDien << endl;
    }
    virtual int TinhTienLuong() = 0;
    int GetSoNamLamViec(){
        return SoNamLamViec;
    }
    int GetSoDiaBanRa(){
        return SoDiaBanRa;
    }
    int GetSoBuoiTrinhDien(){
        return SoBuoiTrinhDien;
    }
};
class CaSyNoiTieng:public CaSy{
    private:
        int SoGameShowThamGia;
    public:
        int TinhTienLuong(){
            int TienLuong = 3000000 + 500000 * GetSoNamLamViec() + 1200 * GetSoDiaBanRa() + 
            500000 * GetSoBuoiTrinhDien() + 500000 * SoGameShowThamGia;
            return TienLuong;
        }
        void Nhap(){
            CaSy::Nhap();
            cout << "Nhap so luong gameshow da tham gia: ";
            cin >> SoGameShowThamGia;
        }
        void Xuat(){
            CaSy::Xuat();
            cout << "So Game Show Tham Gia " << SoGameShowThamGia;
        }
};
class CaSyChuaNoiTieng:public CaSy{
    public:
        int TinhTienLuong(){
            int TienLuong = 3000000;
            TienLuong += 500000* GetSoNamLamViec() + 1000 * GetSoDiaBanRa() + 200000* GetSoBuoiTrinhDien();
            return TienLuong;
        }
};
int main(){
    CaSy** DSCaSy;
    int SLCaSy;
    cout << "Hay nhap vao so luong ca sy: ";
    cin >> SLCaSy;
    cout << endl;
    DSCaSy = new CaSy*[SLCaSy];
    bool PhanLoai; // true = CaSyNoiTieng; false = CaSyChuaNoiTieng;
    for (int i = 0; i < SLCaSy; i++){
        cout << "Nhap vao phan loai ca sy, 1 = CaSyNoiTieng, 0 = CaSyChuaNoiTieng " << endl;
        cin >> PhanLoai;
        if (PhanLoai){
            DSCaSy[i] = new CaSyNoiTieng;
        }
        else {
            DSCaSy[i] = new CaSyChuaNoiTieng;
        }
        DSCaSy[i] -> Nhap();
    }
    int maxluong = DSCaSy[0] -> TinhTienLuong();
    int vitri =0;
    for (int i = 0; i < SLCaSy; i++){
        if (DSCaSy[i]->TinhTienLuong() >= maxluong){
            maxluong = DSCaSy[i]->TinhTienLuong();
            vitri = i;
        }
    }
    cout << "Ca sy co luong cao nhat la: ";
    DSCaSy[vitri] -> Xuat();
    for (int i = 0; i < SLCaSy; i++){
        delete DSCaSy[i];
    }
    delete[] DSCaSy;
    return 0;
}