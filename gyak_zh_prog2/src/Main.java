import java.util.Scanner;


public class Main {

    public static void Main(String[] args){

        Scanner in = new Scanner(System.in);
        int feladatszam = in.nextInt();
        System.out.println("Menü száma: ");

        if(feladatszam == 1){
            elsoFeladat();
        }else if(feladatszam == 2){
            masodikFeladat();
        }else if(feladatszam == 3){
            harmadikFeladat();
        }else if(feladatszam == 4){
            negyedikfeladat();
        }



    }

    private static void elsoFeladat() {
        Scanner in = new Scanner(System.in);
        System.out.println("Parcellafelvétel (Helyrajziszám, szőlőfajta, tőkeszám");
        String[] beolv = in.nextLine().split(",");
        SzoloBirtok szoloBirtok = new SzoloBirtok(Integer.parseInt(beolv[0]), Szolofajta.valueOf(beolv[1]), Integer.parseInt(beolv[2]));

    }

    private static void masodikFeladat() {

    }

    private static void harmadikFeladat() {

    }

    private static void negyedikfeladat() {


    }

}
