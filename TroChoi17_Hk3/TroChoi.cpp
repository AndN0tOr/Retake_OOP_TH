#include <iostream>
#include <string.h>

/*
1. Có vẻ như là các đề học kì phụ đều dễ hơn khá nhiều so với học kỳ chính, nhưng kệ cụ nó đi, tao thích học khó đấy

2. Các lõi linh tinh: 
- Phần syntax: Khi khai báo class không nên có dâu ngoặc tròn, để tránh bị mất thời gian fix vấn đề này.

- Lỗi quên gọi hàm nhập sau khi khởi tạo các đối tượng lớp con -> vì cần điều kiện để phân biệt các lớp con trong chương trình
Nên ta sẽ cần phải gọi hàm Nhap() ngay sau khi mà các đối tượng được khởi tạo thành công.

- Lõi không khai báo khi khởi tạo biến kết quả, khi khởi tạo mà không có giá trị ban đầu có thể dẫn đến việc biến bool rơi vào
giá trị bất định, có thể sai nếu chương trình chạy qua pass hết mà không trải qua lần gấn nào cho biến kết quả.

3. Quên chưa xóa phần khai báo mảng động ở class RungChong.

4. Cần phải chú ý kỹ yêu cầu của đề bài, một số đề bài yêu cầu ta không càn phải thông báo kết quả ra ngoài màn hình, nhưng môt
só chương trình thì lại cần, cần phải đặc biệt chú ý ở phần này.


*/
using namespace std;
class NguoiChoi{
    private:
        int* DoCaoNhay;
        int ChieuCao;
        int* DoManhChieu;
    public:
        NguoiChoi(){
            DoCaoNhay = new int[7];
            DoManhChieu = new int[5];
        }
        ~NguoiChoi(){
            delete[] DoCaoNhay;
            delete[] DoManhChieu;
        }
        void Nhap(){
            for (int i = 0; i < 7; i++){
                cin >> DoCaoNhay[i];            
            }
            cin >> ChieuCao;
            for (int i = 0; i < 5; i++){
                cin >> DoManhChieu[i];
            }
        }
        int* getDoCaoNhay(){
            return DoCaoNhay;
        }
        int getChieuCao(){
            return ChieuCao;
        }
        int* getDoManhChieu(){
            return DoManhChieu;
        }
};
class TroChoi{
    public:
        TroChoi(){

        }
        virtual ~TroChoi(){

        }
        virtual void Nhap() = 0;
        virtual bool VuotQua(NguoiChoi*) = 0;

};
class KhuRungChong:public TroChoi{
    private:
        int ChiSoTao;
        int* DoCaoChong;
    public:
        KhuRungChong(){
            DoCaoChong = new int[8];
        };
         ~KhuRungChong(){
            delete[] DoCaoChong;
        }
        void Nhap(){
            for (int i = 0; i < 7; i++){
                cin >> DoCaoChong[i];
            }
        }
        bool VuotQua(NguoiChoi* Nguoi){
            int* ChieuCaoNhay = Nguoi->getDoCaoNhay();
            int ChieuCaoNhayBuff;
            for (int i = 0; i < 7;i++){
                ChieuCaoNhayBuff = ChieuCaoNhay[i] + ChiSoTao;
                if (ChieuCaoNhayBuff <= DoCaoChong[i]){
                    return false;
                } 
            } return true;
        }
        
};
class DuongHamNui:public TroChoi{
    private:
        int DoDaiHam;
        int* ChieuCaoDuongHam;
    public:
        DuongHamNui(){
            
        };
        ~DuongHamNui(){
            delete[] ChieuCaoDuongHam;
        }
        void Nhap(){
            cin >> DoDaiHam;
            ChieuCaoDuongHam = new int[DoDaiHam];
            for (int i = 0; i < DoDaiHam; i++){
                cin >> ChieuCaoDuongHam[i];
            }
        }
        bool VuotQua(NguoiChoi* Nguoi){
            for (int i = 0; i < DoDaiHam; i++){
                if(Nguoi->getChieuCao() > ChieuCaoDuongHam[i]){
                    return false;
                }
            } return true;
        }
};
class QuaiVat:public TroChoi{
    private:
        int* DoManhChieu;
    public:
        QuaiVat(){

        };
        ~QuaiVat(){
            delete[] DoManhChieu;
        }
        void Nhap(){
            DoManhChieu = new int[5];
            for (int i =0 ; i < 5; i++){
                cin >> DoManhChieu[i];
            }
        }
        bool VuotQua(NguoiChoi* Nguoi){
            int NguoiThang =0;
            int QuaiThang =0;
            int* DoManhChieuNguoi = Nguoi->getDoManhChieu();
            for (int i =0; i < 5; i++){
                if (DoManhChieuNguoi[i] > DoManhChieu[i]){
                    NguoiThang ++;
                } else {
                    QuaiThang ++;
                }
            }
            if (NguoiThang > QuaiThang){
                return true;
            } return false;
        }
};



int main(){
    int n; 
    cin >> n;
    TroChoi** DSTroChoi;
    DSTroChoi = new TroChoi*[n];
    int loaiTroChoi;
    for (int i =0; i < n; i++){
        cin>> loaiTroChoi;
        if (loaiTroChoi == 0 ){
            DSTroChoi[i] = new KhuRungChong;
            DSTroChoi[i]->Nhap();
        }
        if (loaiTroChoi == 1){
            DSTroChoi[i] = new DuongHamNui;
            DSTroChoi[i]->Nhap();
        }
        if (loaiTroChoi == 2){
            DSTroChoi[i] = new QuaiVat;
            DSTroChoi[i]->Nhap();
        }
    }
    NguoiChoi NguoiChoiChinh;
    NguoiChoiChinh.Nhap();
    bool KetQua = true;
    for (int i =0 ; i < n; i++){
        if (DSTroChoi[i]->VuotQua(&NguoiChoiChinh) == false){
            KetQua = false;
            break;
        }
        
    }
}