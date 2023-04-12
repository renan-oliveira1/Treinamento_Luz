using System;

class Principal{

    static void Main(string[] args)
    {

        Vehicle vehicle = new Vehicle("123", "Agile", "Chrevolet");
        DaysWeek dw = DaysWeek.Friday;
        Console.WriteLine(vehicle.GetName());
    }


    enum DaysWeek{
        Sunsay,
        Monday, 
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
        }

}

class Vehicle{
    private string id;
    private string name;
    private string brand;

    public Vehicle(string id, string name, string brand){
        this.id = id;
        this.name = name;
        this.brand = brand;

    }

    public string GetName(){
        return this.name;
    }
}