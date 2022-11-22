public class SzoloBirtok {

    public int helyrajzi;
    Szolofajta szolofajta;
    double tokeszam;
    EvesTermes evesTermes;


    public SzoloBirtok(int helyrajzi, Szolofajta szolofajta, int tokeszam) {
        this.helyrajzi = helyrajzi;
        this.szolofajta = szolofajta;
        this.tokeszam = tokeszam;
        this.evesTermes = evesTermes;
        this.evesTermes.osszterm =  evesTermes.osszterm/tokeszam;
    }


}