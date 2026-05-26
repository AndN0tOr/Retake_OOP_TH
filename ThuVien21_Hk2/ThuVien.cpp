#include <iostream>
#include <string.h>

using namespace std;
/*
1. Lỗi yêu cầu Min, tức là có thể nó yêu cầu thu lại những sách có giá trị thấp nhất, tức là nhiều sách có thể có giá trị 
giống nhau, nhưng tôi chưa đáp ứng được yêu cầu này của đề bài, có thể giải pháp để khắc phục là dùng 1 vòng lặp để tìm 
giá trị min, sau đó dùng 1 vòng lặp nữa để tìm ra các giá trị bằng với giá trị min.
*/
class Sach{
    private:
        string MaSach;
        string TenSach;
        string NhaXuatBan;
        int SoLuong;
        double DonGia;
    public:
        Sach(){};
        virtual ~Sach(){};
        virtual void Nhap(){
            cin.ignore();
            getline(cin, MaSach);
            cin.ignore();
            getline(cin, TenSach);
            cin.ignore();
            getline(cin, NhaXuatBan);
            cin >> SoLuong;
            cin >> DonGia;
        }
        virtual void Xuat(){
            cout << "Ma Sach: " << MaSach <<endl;
            cout << "Ten Sach: " << TenSach << endl;
            cout << "Nha Xuat Ban: " << NhaXuatBan << endl;
            cout << "So Luong: " << SoLuong << endl;
            cout << "Don Gia: " << DonGia << endl;
        }
        virtual long long tinhThanhTien() = 0;
        string GetNhaXuatBan(){
            return NhaXuatBan;
        }
        int getSoLuong(){
            return SoLuong;
        }
        double getDonGia(){
            return DonGia;
        }
        virtual bool PhanLoaiSach() = 0;

};
class SachGiaoKhoa:public Sach{
    private:
        bool TinhTrang;
    public:
        SachGiaoKhoa(){};
        ~SachGiaoKhoa(){};
        void Nhap(){
            Sach::Nhap();
            cin >> TinhTrang;
        }
        void Xuat(){
            Sach::Xuat();
            cout << "Tinh trang: ";
            if (TinhTrang){
                cout << "Moi" << endl;
            } else {
                cout << "Cu" << endl;
            }
        }
        long long tinhThanhTien()override{
            long long ThanhTien = this->getSoLuong() * this->getDonGia();
            if (TinhTrang){
                return ThanhTien;
            } return ThanhTien* 0.5;
        }
        bool PhanLoaiSach() override{
            return true;
        }

};
class SachThamKhao:public Sach{
    private:
        int TienThue;
    public:
        SachThamKhao(){};
        ~SachThamKhao(){};
        void Nhap(){
            Sach::Nhap();
            cin >> TienThue;
        }
        void Xuat(){
            Sach::Xuat();
            cout << "Tien Thue: " << TienThue << endl;
        }
        long long tinhThanhTien()override{
            long long ThanhTien = this->getSoLuong()  * this->getDonGia() + TienThue;
            // Lỗi
        }
        bool PhanLoaiSach() override{
            return false;
        }

};


int main(){
    // Cau 1
    int n;
    cin >> n;
    bool LoaiSach;
    Sach** ListSach;
    ListSach = new Sach*[n];
    cout << "Loai Sach = 1 -> Sach Giao Khoa; Loai Sach = 0 -> Sach Tham Khao" << endl;
    for (int i =0; i < n; i++){
        cin >> LoaiSach;
        if (LoaiSach){
            ListSach[i] = new SachGiaoKhoa;
        } else {
            ListSach[i] = new SachThamKhao;
        }
        ListSach[i]->Nhap();
    }
    for (int i =0; i < n ;i++){
        ListSach[i]->Xuat();
    }
    // Cau 2
    long long TienSachGiaoKhoa = 0;
    long long TienSachThamKhao = 0;
    long long ThanhTienGKMin = 0;
    int vitriGKMin = 0;
    long long ThanhTienTKMin =0;
    int vitriTKMin = 0;
    long long TienSach = 0;
    for (int i =0 ; i < n; i++){
        TienSach = ListSach[i]->tinhThanhTien();
        if (ListSach[i] ->PhanLoaiSach()){
            TienSachGiaoKhoa += TienSach;
            if (ThanhTienGKMin > TienSach || ThanhTienGKMin == 0){
                ThanhTienGKMin = TienSach;
                vitriGKMin = i;
            } 
        } else {
            TienSachThamKhao += TienSach;
            if (ThanhTienTKMin > TienSach || ThanhTienTKMin == 0){
                ThanhTienTKMin = TienSach;
                vitriTKMin = i;
            } 
        }
    }
    cout << "So tien nha truong phai tra cho cac sach giao khoa: ";
    cout << TienSachGiaoKhoa << endl;
    cout << "So tien nha truong phai tra cho cac sach tham khao: ";
    cout << TienSachThamKhao << endl;
    cout << "Sach Giao khoa co Thanh Tien Phai tra it nhat: " << endl;
    ListSach[vitriGKMin] -> Xuat();
    cout << "Sach Tham khao co thanh tien phai tra it nhat: " << endl;
    ListSach[vitriTKMin] ->Xuat();
    
    // Cau 3 
    string TenNhaXuatBan;
    cin.ignore();
    getline(cin,TenNhaXuatBan);
    cout << "Danh sach cac sach co Nha xuat ban giong voi Nha xuat ban vua nhap: " << endl;
    for (int i =0; i < n; i++){
        if (ListSach[i]->PhanLoaiSach() && ListSach[i]->GetNhaXuatBan() ==  TenNhaXuatBan ){
            ListSach[i]->Xuat();
        }
    }

    for (int i = 0; i < n; i++){
        delete ListSach[i];
    }
    delete[]  ListSach;
    return 0;
}