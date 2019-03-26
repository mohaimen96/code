#include <bits/stdc++.h>
#include <gmp.h>
#include <stdio.h>

using namespace std;


int main()
{

    char inputStr[1024],ept[1024],dpt[1024];
    scanf("%1023s", inputStr);
    /*
       mpz_t is the type defined for GMP integers.
       It is a pointer to the internals of the GMP integer data structure
     */
    mpz_t n,p,q;
    int flag;

//    printf ("Enter your number: ");
//    scanf("%1023s", inputStr); /* NOTE: never every write a call scanf ("%s", inputStr);
//                                  You are leaving a security hole in your code. */

    /* 1. Initialize the number */
    mpz_init(n);
    mpz_init(p);
    mpz_init(q);
//    mpz_set_ui(n,0);
//
//    /* 2. Parse the input string as a base 10 number */
//    flag = mpz_set_str(n,inputStr, 10);
//    /* If flag is not 0 then the operation failed */
//
//    /* Print n */
//    printf ("n = ");
//    mpz_out_str(stdout,10,n);
//    printf ("\n");
//
//    /* 3. Add one to the number */
//
//    mpz_add_ui(n,n,1); /* n = n + 1 */
//
//    /* 4. Print the result */
//
//    printf (" n +1 = ");
//    mpz_out_str(stdout,10,n);
//    printf ("\n");
//
//
//    /* 5. Square n+1 */
//
//    mpz_mul(n,n,n); /* n = n * n */
//
//
//    printf (" (n +1)^2 = ");
//    mpz_out_str(stdout,10,n);
//    printf ("\n");
//
//
//    /* 6. Clean up the mpz_t handles or else we will leak memory */
//    mpz_clear(n);
//


    int PRIMESIZE;
    cout<<"Enter No of bits for P and Q: ";
    cin>>PRIMESIZE;


    //P Q
    char* p_str = new char[PRIMESIZE+1];
    char* q_str = new char[PRIMESIZE+1];

    p_str[0] = '1';
    q_str[0] = '1';


    for(int i=1; i<PRIMESIZE; i++)
    {
        p_str[i] = char((rand()%2)+48);
        q_str[i] = char((rand()%2)+48);
    }




    p_str[PRIMESIZE] = '\0';
    q_str[PRIMESIZE] = '\0';

    cout<<p_str<<endl;
    cout<<q_str<<endl;

    mpz_set_str(p,p_str,2);
    mpz_set_str(q,q_str,2);


    mpz_nextprime(p,p);
    mpz_nextprime(q,q);

    //P Q


    cout<<endl<<"p = ";
    mpz_out_str(stdout,10,p);

    cout<<endl<<endl<<"q = ";
    mpz_out_str(stdout,10,q);

    mpz_mul(n,p,q);
    cout<<endl<<endl<<"n = ";
    mpz_out_str(stdout,10,n);

    mpz_t phi,a,b;
    mpz_init(a);
    mpz_init(b);
    mpz_init(phi);
    mpz_sub_ui(a,p,1);
    mpz_sub_ui(b,q,1);
    mpz_mul(phi,a,b);
    cout<<endl<<endl<<"phi = ";
    mpz_out_str(stdout,10,phi);

    mpz_t e,gcd;
    mpz_init(e);
    mpz_init(gcd);
    mpz_set_ui(e,2);

    while(1)
    {
        mpz_gcd(gcd,phi,e);
        if(mpz_cmp_si(gcd,1)==0)
        {
            break;
        }
        mpz_add_ui(e,e,1);
    }
    cout<<endl<<endl<<"e = ";
    mpz_out_str(stdout,10,e);

    mpz_t d,e_inv;
    mpz_init(d);
    mpz_init(e_inv);
    int k=2;

    mpz_mul_ui(phi,phi,k);
    mpz_add_ui(phi,phi,1);
    mpz_div(d,phi,e);

    cout<<endl<<endl<<"d = ";
    mpz_out_str(stdout,10,d);

    mpz_t msg,enc,dec;
    mpz_init(msg);
    mpz_init(enc);
    mpz_init(dec);
    mpz_set_ui(msg,0);
    mpz_set_str(msg,inputStr,10);
    cout<<endl<<endl<<"msg = ";
    mpz_out_str(stdout,10,msg);

    mpz_powm_ui(enc,msg,mpz_get_ui(e),n);
    cout<<endl<<endl<<"encrypted = ";
    mpz_out_str(stdout,10,enc);

    mpz_powm_ui(dec,enc,mpz_get_ui(d),n);
    cout<<endl<<endl<<"decrypted = ";
    mpz_out_str(stdout,10,dec);



///POWER
    //mpz_powm(v,l,e,n);//v=(l^e) mod n

///Division: l=s/r
//    mpz_invert(r_inv,r,n);
//    mpz_mul(l,s,r_inv);

}
