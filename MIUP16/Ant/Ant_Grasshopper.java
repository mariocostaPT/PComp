import java.io.BufferedReader;
//import java.io.BufferedWriter;
//import java.io.IOException;
import java.io.InputStreamReader;
//import java.io.OutputStreamWriter;

import static java.lang.Math.pow;





public class Ant_Grasshopper {





    public static void main(String[] args) {

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        
        try {
        int n = Integer.parseInt(reader.readLine());
        double y, B, r;
        double a, I, I_Sum;

        double array[] = new double[n];

        //System.out.println("Number of Cases: #" + n);

        String line;

        //loop to get cases
        for (int x = 1; x <= n; x++){
            line = reader.readLine();
            String spliter[] = line.split(" ");

            y = Double.parseDouble(spliter[0]);
            B = Double.parseDouble(spliter[1]);
            r = Double.parseDouble(spliter[2]);

            I = r * 0.01;

            I_Sum = (1-pow((1+I), y))/(1- ( 1 + I));

            a = (B* pow((1 + I), y)) / (I_Sum);

            array[x-1] = a * y ;
        }

        reader.close();
        //BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        for (int x = 1; x <= n; x++){
            //writer.newLine( Double.toString(array[x-1]) );
            System.out.println(String.format("%.3f", array[x-1]));
        }



        } catch (Exception error){
            System.out.println("Erro Input Buffer -" + error);
        }
    }




}