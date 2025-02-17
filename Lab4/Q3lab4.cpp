#include<iostream>
using namespace std;

class Invoice{
    private:
        string part_number;
        string part_descri;
        int quantity;
        double price_per_item;
    public:
        Invoice(string part_num, string part_des, int qnty, double ppi){
            part_number = part_num;
            part_descri = part_des;
            if(qnty >= 0){
                quantity = qnty;
            }
            else quantity = 0;
            if(ppi >= 0){
                price_per_item = ppi;
            }
            else price_per_item = 0.0;
        }

        double getInvoiceAmount(){
            return quantity * price_per_item;
        }

        void getPartNumber(){
            cout<<"Part number is: "<<part_number<<endl;
        }

        void getPartDescription(){
            cout<<"Part Description is: "<<part_descri<<endl;
        }

        void getQuantity(){
            cout<<"Quantity is: "<<quantity<<endl;
        }

        void getPricePerItem(){
            cout<<"Price per item is: "<<price_per_item<<endl;
        }
};

int main(){
    Invoice i("NQ34W","used",4,10);
    cout<<"Invoice amount is: "<<i.getInvoiceAmount()<<endl;
    i.getPartNumber();
    i.getPartDescription();
    i.getQuantity();
    i.getPricePerItem();

    return 0;
}