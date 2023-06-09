#include <fstream>
#include <unistd.h> 
#include <string.h>  
#include <string>
#include <iostream>
using namespace std;

//uBlock-256
//test_nus_Pr.cpp and nus_Pr.cpp

int main(){

    ifstream frr;
    frr.open("result.txt", ios::in);
    string read1;                

    getline(frr, read1);
    if(read1.compare("Valid.") != 0){

        FILE *fp3 = NULL; 
        fp3 = popen("echo '' > result.txt", "r");
        pclose(fp3); 
            
             
        FILE *fp1 = NULL; 
        fp1 = popen("g++ nus_Pr.cpp", "r");
        pclose(fp1);

        FILE *fp2 = NULL; 
        fp2 = popen("./a.out", "r");
        pclose(fp2);

        FILE *fp = NULL; 
        FILE *fh = NULL; 
        fp = popen("stp 8R_nus_Pr.cvc --cryptominisat", "r");
        
        char buff;
        buff = getc(fp);
        fh = fopen("result.txt", "w");
        while (buff != EOF)  
        {
            fputc(buff, fh);
            buff = getc(fp);
        }
        pclose(fp); 
        fclose(fh);


        
        ifstream frrr;
        frrr.open("result.txt", ios::in);
        string read11;                

        getline(frrr, read11);
        if(read11.compare("") != 0){
    

        //read
        ifstream fr;
        fr.open("result.txt", ios::in); 

        string read;
        int pos1, pos2;
        string str;
        while (!fr.eof()){  //end of file
            getline(fr, read);
            string cc = "ASSERT( total_Pr = 0x";
            pos1 = read.find(cc);
            pos2 = read.find("0x");
            if(pos1 >= 0){
                str = read.substr(pos2+2, 3);
            }
        }
        fr.close();
        
        
        
        
        //write
        ifstream fw1;
        fw1.open("nus_Pr.cpp", ios::in);
        ofstream fw2;
        fw2.open("temp.cpp", ios::out);

        string del1 = "fprintf(fp, \"QUERY FALSE;\\n\");";
        string del2 = "fprintf(fp, \"COUNTEREXAMPLE;\");";
        string del3 = "fclose(fp); ";
        string del4 = "return 0;}";
        string del;
        while(getline(fw1, del)){
            if(del.compare(del1)!=0){
            if(del.compare(del2)!=0){
            if(del.compare(del3)!=0){
            if(del.compare(del4)!=0){
                fw2 << del << endl;
            }}}}
        }
        fw1.close();
        fw2.close();

        ifstream fw22;
        fw22.open("temp.cpp", ios::in);
        ofstream fw11;
        fw11.open("nus_Pr.cpp", ios::out);
        while(getline(fw22, del)){
            fw11 << del << endl;
        }
        remove("temp.cpp");
        fw11.close();
        fw22.close();


        ofstream fw;
        fw.open("nus_Pr.cpp", ios::app);
        string strc = "fprintf(fp, \"ASSERT NOT(total_Pr = 0hex" + str + ");\\n\");";
        fw << strc << endl;
        fw << del1 << endl << del2 << endl << del3 << endl << del4 << endl;
        fw.close();

        }
        frrr.close();

        FILE *fpp1 = NULL; 
        fpp1 = popen("g++ -o test_nus_Pr test_nus_Pr.cpp", "r");
        pclose(fpp1); 

        FILE *fpp2 = NULL; 
        fpp2 = popen("./test_nus_Pr", "r");
        pclose(fpp2);


    }

    frr.close();
                
    return 0;
}
