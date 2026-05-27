#include <iostream>
#include <string.h>

using namespace std;

class VatChu{
    private:
        string MaSo;
        KhaNangMienDich* SucDeKhang;
        Virus** CacBenh;
    public:
        VatChu(){
            CacBenh = new Virus*[3];
            CacBenh[0] = new CoVid19;
            CacBenh[0] = new Ebola;
            CacBenh[0] = new HIV;
        };
        ~VatChu(){
            delete SucDeKhang;
            for (int i= 0; i < 3; i++){
                delete CacBenh[i];
            }
            delete[] CacBenh;
        }
        void Nhap(){
            int LoaiDeKhang;
            cin.ignore();
            cin >> MaSo;
            cin >> LoaiDeKhang;
            if (LoaiDeKhang == 0){
                SucDeKhang = new MienDichCao;
            } else if (LoaiDeKhang == 1){
                SucDeKhang = new MienDichTB;
            } else if (LoaiDeKhang == 2){
                SucDeKhang = new MienDichThap;
            }
        }
        void ChoNhiemBenh(){
            for (int i =0; i < 3; i++){
                CacBenh[i]->NhiemBenh();
            }
        }
        void TiemVC(){
            for (int i =0; i < 3; i++){
                CacBenh[i]->TiemVC();
            }
        }
        bool CoBiTuVong(){
            double KqRdCovid = RandomDouble();
            double NguongTuCovid = CacBenh[0]->TinhXacSuatTuVong(SucDeKhang);
            double KqRdEbola = RandomDouble();
            double NguongTuEbola = CacBenh[1]->TinhXacSuatTuVong(SucDeKhang);
            double KqRdHIV = RandomDouble();
            double NguongTuHIV = CacBenh[2]->TinhXacSuatTuVong(SucDeKhang);
            if (KqRdCovid > NguongTuCovid || KqRdEbola > NguongTuEbola || KqRdHIV > NguongTuHIV){
                return false;
            }
            return true;
        }
        bool GetTrieuChungNang(){
            if (CacBenh[0]->getTrieuChungNang() || CacBenh[1]->getTrieuChungNang() || CacBenh[2]->getTrieuChungNang()){
                return true;
            }
        }
        void InRaTrieuChung(){
            if (CacBenh[0]->getKoTrieuChung()){
                cout << "ko co trieu chung." << endl;
            } else if (CacBenh[0]->getTrieuChungNhe()){
                CacBenh[0]->InRaTrieuChungNhe();
            } else if (CacBenh[0]->getTrieuChungNang()){
                CacBenh[0]->InRaTrieuChungNang();
            }
            if (CacBenh[1]->getKoTrieuChung()){
                cout << "ko co trieu chung." << endl;
            } else if (CacBenh[1]->getTrieuChungNhe()){
                CacBenh[1]->InRaTrieuChungNhe();
            } else if (CacBenh[1]->getTrieuChungNang()){
                CacBenh[1]->InRaTrieuChungNang();
            }
            if (CacBenh[2]->getKoTrieuChung()){
                cout << "ko co trieu chung." << endl;
            } else if (CacBenh[0]->getTrieuChungNhe()){
                CacBenh[2]->InRaTrieuChungNhe();
            } else if (CacBenh[0]->getTrieuChungNang()){
                CacBenh[2]->InRaTrieuChungNang();
            }
        }
};
class KhaNangMienDich{
    public:
        KhaNangMienDich(){};
        virtual ~KhaNangMienDich(){};
        virtual bool LaSucDeKhangCao(){
            return false;
        }
        virtual bool LaSucDeKhangTb(){
            return false;
        }
        virtual bool LaSucDeKhangThap(){
            return false;
        }
};
class MienDichCao: public KhaNangMienDich{
    public:
        MienDichCao(){};
        ~MienDichCao(){};
        bool LaSucDeKhangCao()override{
            return true;
        }
};
class MienDichTB: public KhaNangMienDich{
    public:
        MienDichTB(){};
        ~MienDichTB(){};
        bool LaSucDeKhangTb() override{
            return true;
        }
};
class MienDichThap: public KhaNangMienDich{
    public:
        MienDichThap(){};
        ~MienDichThap(){};
        bool LaSucDeKhangThap() override{
            return true;
        }
};
class Virus{
    private:
        bool DuongTinh;
        bool DaTiemVC;
        static float TyleTuVongTb;
        bool KoTrieuChung;
        bool TrieuChungNhe;
        bool TrieuChungNang;
    public:
        Virus(){
            DaTiemVC = false;
            DuongTinh = false;
            TyleTuVongTb = 0;
        }
        ~Virus(){}
        void NhiemBenh(){
            DuongTinh = true;
        }
        void TiemVC(){
            DaTiemVC = true;
        }
        bool getDuongTinh(){
            return DuongTinh;
        }
        bool getDaTiemVC(){
            return DaTiemVC;
        }
        void SetTyleTuVongTb(float Tyle){
            TyleTuVongTb = Tyle;
        }
        float GetTyleTuVongTb(){
            return TyleTuVongTb;
        }
        bool getTrieuChungNang(){
            return TrieuChungNang;
        }
        bool getTrieuChungNhe(){
            return TrieuChungNhe;
        }
        bool getKoTrieuChung(){
            return KoTrieuChung;
        }
        
        virtual void InRaTrieuChungNhe() = 0;
        virtual void InRaTrieuChungNang() = 0;
        void SetTrieuChung(KhaNangMienDich* KNMienDich){
            float MucKoTrieuChung;
            float MucTrieuChungNhe;
            float MucTrieuChungNang;
            double DiemRoi = RandomDouble();
            if (this->getDaTiemVC()){
                if (KNMienDich->LaSucDeKhangCao()){
                    if (DiemRoi < 0.7){
                        KoTrieuChung = true;
                    } else if (DiemRoi >= 0.7 && DiemRoi <= 0.95 ){
                        TrieuChungNhe = true;
                    } else {
                        TrieuChungNang = true;
                    }
                }
                if (KNMienDich->LaSucDeKhangTb()){
                    if (DiemRoi < 0.2){
                        KoTrieuChung = true;
                    } else if (DiemRoi >= 0.2 && DiemRoi <= 0.7 ){
                        TrieuChungNhe = true;
                    } else {
                        TrieuChungNang = true;
                    }
                }
                if (KNMienDich->LaSucDeKhangThap()){
                    if (DiemRoi < 0.1){
                        KoTrieuChung = true;
                    } else if (DiemRoi >= 0.1 && DiemRoi <= 0.5 ){
                        TrieuChungNhe = true;
                    } else {
                        TrieuChungNang = true;
                    }
                }
            } else {
                if (KNMienDich->LaSucDeKhangCao()){
                    if (DiemRoi < 0.5){
                        KoTrieuChung = true;
                    } else if (DiemRoi >= 0.5 && DiemRoi <= 0.85 ){
                        TrieuChungNhe = true;
                    } else {
                        TrieuChungNang = true;
                    }
                }
                if (KNMienDich->LaSucDeKhangTb()){
                    if (DiemRoi < 0.1){
                        KoTrieuChung = true;
                    } else if (DiemRoi >= 0.1 && DiemRoi <= 0.5 ){
                        TrieuChungNhe = true;
                    } else {
                        TrieuChungNang = true;
                    }
                }
                if (KNMienDich->LaSucDeKhangThap()){
                    if (DiemRoi < 0.05){
                        KoTrieuChung = true;
                    } else if (DiemRoi >= 0.05 && DiemRoi <= 0.2 ){
                        TrieuChungNhe = true;
                    } else {
                        TrieuChungNang = true;
                    }
                }
            }
        }
        float TinhXacSuatTuVong(KhaNangMienDich* KNMienDich){
            float TyleTuvong =0;
            if (this->getDaTiemVC()){
                if (KNMienDich->LaSucDeKhangCao()){
                    TyleTuvong = 0.4 * TyleTuVongTb;
                }
                if (KNMienDich->LaSucDeKhangTb()){
                    TyleTuvong = 0.6 * TyleTuVongTb;
                }
                if (KNMienDich->LaSucDeKhangThap()){
                    TyleTuvong = 0.8 * TyleTuVongTb;
                }
            } else {
                if (KNMienDich->LaSucDeKhangCao()){
                    TyleTuvong = 0.5 * TyleTuVongTb;
                }
                if (KNMienDich->LaSucDeKhangTb()){
                    TyleTuvong = 0.7 * TyleTuVongTb;
                }
                if (KNMienDich->LaSucDeKhangThap()){
                    TyleTuvong =  TyleTuVongTb;
                }
            }
            return TyleTuvong;
        }

};
class CoVid19: public Virus{
    private:
         
    public:
        CoVid19(){
            SetTyleTuVongTb(0.03);
        };
        ~CoVid19(){};
        void InRaTrieuChungNhe()override{
            cout << "Triệu chứng nhẹ của Covid-19 giống như cảm cúm thông thường như sốt, ";
            cout << "ho, mất vị giác trong vài ngày rồi khỏi." << endl;
        }
        void InRaTrieuChungNang() override{ 
            cout << "Triệu chứng nặng của Covid-19 bao gồm sốt cao, ho khan, ";
            cout << "khó thở và đôi lúc kèm theo đau đầu dữ dội." << endl;
        }       
};
class Ebola: public Virus{
    private:
    public:
        Ebola(){
            SetTyleTuVongTb(0.5);
        };
        ~Ebola(){};
        void InRaTrieuChungNhe() override{
            cout << "Bao gồm sốt, đau họng, đau cơ và đau đầu. " << endl;
        }
        void InRaTrieuChungNang() override{
            cout << "Tnôn mửa, tiêu chảy và nặng nhất là xuất huyết cả ngoài lẫn bên trong. " << endl;
        }       
};
class HIV: public Virus{
    private:
    public:
        HIV(){
            SetTyleTuVongTb(0.9);
        };
        ~HIV(){};
        void InRaTrieuChungNhe()override{
            cout << "cảm sốt " << endl;
        }
        void InRaTrieuChungNang()override{
            cout << "mệt mỏi cực độ không giải thích được, sưng hạch kéo dài, lở loét, viêm phổi, tiêu chảy nặng" << endl;
        }       
};


int main(){
    // Cau 1
    int n; 
    cin >> n;
    VatChu* DSVatChu;
    DSVatChu = new VatChu[n];
    for (int i =0; i < n; i++){
        DSVatChu[i].Nhap();
    }
    for (int i =0; i < n; i++){
        DSVatChu[i].ChoNhiemBenh();
    }

    // Cau 2
    for (int i =0; i < n;i ++){
        DSVatChu[i].InRaTrieuChung();
        if (DSVatChu[i].CoBiTuVong()){
            cout << "Vat chu da tu vong." << endl;
        } else{
            cout << "Vat chu van con song." << endl;
        }
    }

    // Cau 3
    VatChu* DSVatChu2 = new VatChu[n];
    for (int i = 0; i < n; i++){
        DSVatChu2[i].Nhap();
    }
    for (int i = 0; i < n; i++){
        DSVatChu2[i].TiemVC();
        DSVatChu2[i].ChoNhiemBenh();
    }
    int SLTuvong = 0;
    int SLTCNang = 0;
    for (int i= 0; i< n; i++){
        if (DSVatChu2[i].GetTrieuChungNang()){
            SLTCNang += 1;
        }
        if (DSVatChu2[i].CoBiTuVong()){
            SLTuvong += 1;
        }
    }
    cout << "SL Vat chu co trieu chung nang:  "<< SLTCNang << endl;
    cout << "SL Vat chu tu vong: " << SLTuvong << endl;


    delete[] DSVatChu;
    delete[] DSVatChu2;
    return 0;
}