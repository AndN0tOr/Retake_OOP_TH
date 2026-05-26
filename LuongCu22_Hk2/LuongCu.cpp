#include <iostream>
#include <string.h>

using namespace std;
/*
Điểm 5/10
Các lỗi:
1. Chèn lại hàm destructor vào trong hàm con mặc dù đã có từ khóa virtual.

2. Trong các điều kiện để xét con vật có phát triển bất bình thường hay không, vẫn đang bị lỗi logic 
khi dùng toán tử and thay vì toán tử or, đẫn đến logic ở hàm này bị saoi hoàn toàn.

3. khi tạo một hàm thuần ảo, thì tất cả các lớp con sẽ phải có định nghĩa cho hàm này, nên
giải pháp đặt ra là một là dùng hàm thuần ảo, nếu các lớp con đều cần hàm đó, hoặc nếu chỉ dùng cho 
một/ một vài lớp thì không dùng hàm thuần ảo, mà cần định nghĩa mặc định cho những lớp đối tượng không
dùng đến hàm này.

4. Khi các lớp con có thêm thuộc tính, cần phải lưu ý việc thêm hàm nhập xuất, bởi vì hàm cha sẽ có số 
thuộc tính ít hơn hàm con, dẫn đến nếu không chỉnh hàm nhập/ xuất thì dễ bỏ qua thuộc tính đặc biết của
lớp con.

5. Khi copy lớp, cần phải chú ý không để sai nội dung với lớp được mô tả trong đề bài.

6. Khi đặt tên biến trong hàm cho một thông số đã có trong đối tượng, có thể truy cập trực tiếp đối tượng,
hoặc dùng tên khác để đặt tên biến, tránh gây nhầm lẫn cho compiler.
*/
class VongDoi{
    private:
        int* CacGiaiDoan;
    public:
        VongDoi(){
            CacGiaiDoan = new int[4];
        };
        virtual ~VongDoi(){
            delete[] CacGiaiDoan;
        };
        virtual void Nhap(){ // Lỗi số 4. Them virtual cho các lớp Bướm và Muỗi
            for (int i =0; i < 4; i++){
                cin >> CacGiaiDoan[i];
            }
        }
        virtual bool LaMuoi(){
            return false;
        }
        int getGD1(){
            return CacGiaiDoan[0];
        }
        int getGD2(){
            return CacGiaiDoan[1];
        }
        int getGD3(){
            return CacGiaiDoan[2];
        }
        int getGD4(){
            return CacGiaiDoan[3];
        }
        virtual int getGD5(){
            return 0;
        };
        virtual int GetTuTrungThanhNhong(){
            return 0;
        };       
        virtual bool PhatTrienBatBinhThuong() = 0;
};
class VongDoiMuoi:public VongDoi{
    private:
    public:
        VongDoiMuoi(){}; 
        ~VongDoiMuoi(){}; // Lỗi 1. Đã xóa phầm gọi hàm hủy bỏ từ lớp cha
        bool LaMuoi(){
            return true;
        }
        int GetTuTrungThanhNhong() override{
            return this->getGD2() + this->getGD3(); 
        }
        bool PhatTrienBatBinhThuong() override{
            int GD1 = this->getGD1();
            int GD2 = this->getGD2();
            int GD3 = this->getGD3();
            int GD4 = this->getGD4();
            if (GD1 < 1 && GD1 > 3){
                return true;
            } else if (GD2 < 4 && GD2 > 10 ){
                return true;
            } else if (GD2 < 2 && GD2 > 3){
                return true;
            } else if (GD4 < 5 && GD4 > 8){
                return true;
            } else return false;
        }
};
class VongDoiEch:public VongDoi{
    private:
        int GD5;
    public:
        VongDoiEch(){};
        ~VongDoiEch(){}; 
        int getGD5() override{
            return GD5;
        }
        /* Fix lỗi Nhap thiếu thông số.
        void Nhap(){
            VongDoi::Nhap();
            cin>> GD5;
        }
        */
        bool PhatTrienBatBinhThuong() override{
            int GD1 = this->getGD1();
            int GD2 = this->getGD2();
            int GD3 = this->getGD3();
            int GD4 = this->getGD4();
            if (GD1 < 7 && GD1 > 21){
                return true;
            } else if (GD2 <28  && GD2 > 35){
                return true;
            } else if (GD3 <42 && GD2 > 63){ // Sai lỗi chính tả, khi đang xét giai đoạn 3
                return true;
            } else if (GD4 < 7 && GD4 > 28){
                return true;
            } else if (GD5 < 2 * 365 && GD5 > 4*365){
                return true;
            } return false;
        }
};
class VongDoiBuom:public VongDoi{
    private:
         // lỗi 5:Đã xóa phần khai báo thêm giai đoạn 5, Copy dẫn đến có những thuộc tính bị thừa, không cần thiết.
    public:
        VongDoiBuom(){}; 
        ~VongDoiBuom(){}; // Đã xóa phần gọi hàm hủy từ lớp cha. 
        bool PhatTrienBatBinhThuong() override{
            int GD1 = this->getGD1();
            int GD2 = this->getGD2();
            int GD3 = this->getGD3();
            int GD4 = this->getGD4();
            //int GD5 = GD5; // Lỗi khi copy nguyên class con ếch sang lớp con bướm.
            if (GD1 < 3 && GD1 > 8){
                return true;
            } else if (GD2 <15  || GD2 > 16){
                return true;
            } else if (GD3 != 10){
                return true;
            } else if (GD4 < 2 || GD4 > 3){
                return true;
            } return false;
        }
};


int main(){
    // Cau 1
    int n;
    cin >> n;
    VongDoi** DSConVat;
    int loaiConVat;
    DSConVat = new VongDoi*[n];
    for (int i =0; i < n; i++){
        cin >> loaiConVat;
        if (loaiConVat == 0){
            DSConVat[i] = new VongDoiMuoi;
            DSConVat[i]->Nhap();
        } else if (loaiConVat == 1){
            DSConVat[i] = new VongDoiEch;
            DSConVat[i]->Nhap();
        } else if (loaiConVat == 2){
            DSConVat[i] = new VongDoiBuom;
            DSConVat[i]->Nhap();
        }
    }
    // Cau 2
    for (int i =0; i < n; i++){
        if (DSConVat[i]->PhatTrienBatBinhThuong()){
            cout << i << " ";
        }
    }
    cout << endl;
    // Cau 3
    int ThoiGianMax = 0;
    int vitri =0;
    int ThoiGian =0;
    for (int i =0; i < n; i++){
        if (DSConVat[i]->LaMuoi()){
            ThoiGian = DSConVat[i] -> GetTuTrungThanhNhong();
            if (ThoiGian > ThoiGianMax){
                ThoiGianMax = ThoiGian;
                vitri = i;
            }
        }
    }
    cout << "Con muoi co thoi gian chuyen tu trung thanh nhong lau nhat: " << vitri;


    for (int i =0; i< n; i++){
        delete DSConVat[i];
    }
    delete[] DSConVat;
    return 0;
}