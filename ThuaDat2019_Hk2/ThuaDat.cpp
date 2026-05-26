#include <iostream>
#include <string.h>

using namespace std;
/*
1. Trong trường hợp tạo mảng con trỏ lớp cha để nhằm chỉ đến lớp con, nhưng lớp con chỉ có một số lớp thực sự cần
phải sử dụng hàm đó, có thể sử dụng giá trị mặc định ở các lớp còn lại
- Không nhất thiết phải tạo một mảng lưu lại giá trị lựa chọn lúc chọn giá trị nhập vào của các đối tượng trong
mảng gốc.

2. kiểm tra lỗi chính tả khi sử dụng các hàm viết lại - override 

3. khi tạo lớp người, cần phải chú ý nhập xuất thông tin của lớp người - khi chèn lớp người giống như một 
biến private trong lớp đói tượng khác.

4. Lỗi đồng sở hữu - trong bài này, đề bài đã nói rõ là một thửa đát có thể được cùng sở hữu bởi nhiều người
vậy thì sẽ tốt hơn nếu có biến int số người sở hữu và một mảng động để lưu thông tin những người này.

5. Quên xóa bộ nhớ sau khi khai báo các mảng động

6. Sử dụng override có thể tránh được lỗi chính tả khi sử dụng định nghĩa hàm ảo?
*/
class Nguoi{
    private:
        string HoTen;
        int NamSinh;
        string CMND;
        string HoKhauThuongTru;
    public:
        Nguoi(){

        };
        ~Nguoi(){

        };
        void Nhap(){
            cin.ignore();
            getline(cin, HoTen);
            cin >> NamSinh;
            cin >> CMND;
            cin.ignore();
            getline(cin, HoKhauThuongTru);
        }
        void Xuat(){
            cout << "Ho Ten: " << HoTen << endl;
            cout << "Nam sinh: " << NamSinh << endl;
            cout << "CMND: " << CMND << endl;
            cout << "Ho Khau Thuong tru: " << HoKhauThuongTru << endl; 
        }
};
class ThuaDat{
    private:
        string SoChungNhan;
        Nguoi* NguoiSoHuu;
        int SoThuaDat;
        int SoToBanDo;
        string DiaChiThuaDat;
        float DienTich;
        string NgayCap;
        float DonGiaThue;
    public:
        ThuaDat(){
            NguoiSoHuu = new Nguoi;
        };
        virtual ~ThuaDat(){
            delete NguoiSoHuu;
        }
        virtual void Nhap(){
            cin >> SoChungNhan;
            cin >> SoThuaDat;
            cin >> SoToBanDo;
            cin.ignore();
            getline(cin, DiaChiThuaDat);
            cin >> DienTich;
            cin.ignore();
            getline(cin, NgayCap);
            cin >> DonGiaThue;
        };
        virtual void Xuat(){
            cout << "So Chung Nhan: " << SoChungNhan << endl;
            NguoiSoHuu->Xuat();
            cout << "So Thua Dat: " << SoThuaDat << endl;
            cout << "So To Ban Do: " << SoToBanDo << endl;
            cout << "Dia Chi Thua Dat: " << DiaChiThuaDat << endl;
            cout << "Dien Tich: " << DienTich << endl;
            cout << "Ngay Cap: " << NgayCap << endl;
            cout << "Don Gia Thue: " << DonGiaThue << endl;
        }
        virtual int GetThoiHanSuDung();
        float TinhTienThue(){
            return DienTich * DonGiaThue;
        }
};
class ThuaDatNongNghiep: public ThuaDat{
    private:
        int ThoiHanSuDung;
    public:
        ThuaDatNongNghiep(){

        };
        ~ThuaDatNongNghiep(){};
        void Nhap(){
            ThuaDat::Nhap();
            cin >> ThoiHanSuDung;
        }
        void Xuat(){
            ThuaDat::Xuat();
            cout << "Thoi han su dung: " << ThoiHanSuDung;
        }
        int GetThoiHanSuDUng(){
            return ThoiHanSuDung;
        }
};
class ThuaDatPhiNongNghiep: public ThuaDat{
    public:
        ThuaDatPhiNongNghiep(){};
        ~ThuaDatPhiNongNghiep(){};
};

int main(){

    // cau 1
    int n;
    cin >> n;
    ThuaDat** DSThuaDat;
    DSThuaDat = new ThuaDat*[n];
    bool* DatNongNghiep;
    DatNongNghiep = new bool[n];
    for (int i = 0; i < n; i++){
        cin >> DatNongNghiep[i];
        if (DatNongNghiep[i]){
            DSThuaDat[i] = new ThuaDatNongNghiep;
            DSThuaDat[i]->Nhap();
        } else {
            DSThuaDat[i] = new ThuaDatPhiNongNghiep;
            DSThuaDat[i]->Nhap();
        }
    }

    // cau 2
    float TongTienThue = 0;
    float TienThueMax = 0;
    float TienThue = 0;
    int vitri;
    for (int i =0; i < n; i++){
        float TienThue = DSThuaDat[i]->TinhTienThue();
        TongTienThue += TienThue;
        if (TienThue > TienThueMax){
            TienThueMax = TienThue;
            vitri = i;
        }
    }
    DSThuaDat[vitri]->Xuat();

    // cau 3
    int NamHienTai = 2026;
    for (int i =0; i < n; i++){
        if (DatNongNghiep[i]){
            if (DSThuaDat[i]->GetThoiHanSuDung() < NamHienTai){
                cout << "Thua dat nong nghiep nay da het thoi han su dung: " << endl;
                DSThuaDat[i]->Xuat();
            } continue;
        } continue;
    }



    return 0;
}