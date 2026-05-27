#include <iostream>
#include <string.h>

using namespace std;

class PhuongThucVC{
    private:
        string MaVanDon;
        string TenDonViVC;
        int SoChang;
        double* LoTrinh;
        double TongTrongLuong;
    public:
        PhuongThucVC(){
            LoTrinh = nullptr;
        };
        virtual ~PhuongThucVC(){
            delete[] LoTrinh;
        };
        virtual double TinhPhiDV()= 0;
        virtual void Nhap(){
            cout << "Hay nhap vao ma van don: ";
            cin >> MaVanDon;
            cin.ignore();
            cout << "Hay nhap vao Ten Don vi Van chuyen: ";
            getline(cin, TenDonViVC);
            cout << "Hay nhap vao so chang";
            cin >> SoChang;
            LoTrinh = new double[SoChang];
            for (int i =0; i < SoChang; i++){
                cout << "Nhap vao do dai chang: ";
                cin >> LoTrinh[i];
            }
            cout << "Nhap vao tong trong luong: ";
            cin >> TongTrongLuong;
        }
        virtual void Xuat(){
            cout << "Ma Van Don: " << MaVanDon << endl;
            cout << "Ten Don vi Van chuyen: " << TenDonViVC << endl;
            cout << "Tong Quang Duong: " << this->TinhQuangDuong() << endl;
            cout << "Tong trong luong: " << this->TongTrongLuong << endl;
        }
        double TinhQuangDuong(){
            double TongQuangDuong = 0;
            for (int i =0 ; i < SoChang; i++){
                TongQuangDuong += LoTrinh[i];
            }
            return TongQuangDuong;
        }
        virtual bool LaDrone(){
            return false;
        }
        virtual bool LaXeTai(){
            return false;
        }
};
class Truck: public PhuongThucVC{
    private:
        double PhiCauDuong;
    public:
        Truck(){};
        virtual ~Truck(){};
        void Nhap(){
            PhuongThucVC::Nhap();
            cout << "Hay nhap phi cau duong: ";
            cin >> PhiCauDuong;
        }
        void Xuat(){
            PhuongThucVC::Xuat();
            cout << "Phi cau duong" << PhiCauDuong << endl;
        }
        bool LaXeTai()override{
            return true;
        }
        double TinhPhiDV() override{
            double ThanhTien = this->TinhQuangDuong() * 10000 + PhiCauDuong;
            return ThanhTien;
        }

};
class Drone: public PhuongThucVC{
    private:
        double PhiBHBay;
    public:
        Drone(){};
        ~Drone(){};
        void Nhap(){
            PhuongThucVC::Nhap();
            cout << "Hay nhap phi Bh Bay: ";
            cin >> PhiBHBay;
        }
        void Xuat(){
            PhuongThucVC::Xuat();
            cout << "Phi BH Bay" << PhiBHBay << endl;
        }
        bool LaDrone()override{
            return true;
        }
        double TinhPhiDV()override{
            double ThanhTien = this->TinhQuangDuong() * 50000 + PhiBHBay;
            return ThanhTien;
        }

};
class Train: public PhuongThucVC{
    public:
        Train(){};
        ~Train(){};
        double TinhPhiDV()override{
            double ThanhTien = this->TinhQuangDuong() * 5000;
            return ThanhTien;
        }
};
int main(){
    // Cau 1
    int n;
    cout << "Hay nhap vao so luong don hang: " ;
    cin >> n;
    PhuongThucVC** DSDonHang;
    DSDonHang = new PhuongThucVC*[n];
    int LoaiPhuongThuc;
    for (int i = 0; i < n; i++){
        cout << "Nhap vao loai don hang, 0 = Truck, 1 = Drone, 2 = Train;" << endl;
        cin >> LoaiPhuongThuc;
        if (LoaiPhuongThuc == 0){
            DSDonHang[i] = new Truck;
        } else if (LoaiPhuongThuc == 1){
            DSDonHang[i] = new Drone;
        } else if (LoaiPhuongThuc == 2){
            DSDonHang[i] = new Train;
        } else{
            cout << "Loai phuong thuc khong hop le, vui long nhap lai tu dau." << endl;
        }
        DSDonHang[i]->Nhap();
    }

    // Cau 2;
    double TongDoanhThu = 0;
    for (int i = 0; i < n; i++){
        if (DSDonHang[i]->LaDrone()){
            TongDoanhThu += DSDonHang[i]->TinhPhiDV();
        }
    }
    cout << "Tong doanh thu cac don hang su dung Drone: " << TongDoanhThu;

    // Cau 3
    double QDMax =0 ;
    int vitri = -1;
    for (int i =0; i < n; i++){
        if (DSDonHang[i]->LaXeTai()){
            double QuangDuong = DSDonHang[i]->TinhQuangDuong();
            if (QuangDuong > QDMax){
                vitri = i;
                QDMax = QuangDuong;
            }
        }
    }
    if (vitri != -1){
        cout << "Don hang xe tai co quang duong dai nhat la: " << endl;
        DSDonHang[vitri]->Xuat();
    } else {
        cout << "Khong co don hang xe tai nao ca." << endl;
    }

    for (int i = 0; i < n; i++){
        delete DSDonHang[i];
    }
    delete[] DSDonHang;
    return 0;
}