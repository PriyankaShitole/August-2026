//Question 15



class Pattern{
    public static void main(String args[])
    {
        int i, j;

        // Increasing pattern
        for(i = 1; i <= 5; i++)
        {
            for(j = 1; j <= i; j++)
            {
                System.out.print(i);

                if(j < i)
                    System.out.print("*");
            }
            System.out.println();
        }

        // Decreasing pattern
        for(i = 5; i >= 2; i--)
        {
            for(j = 1; j <= i; j++)
            {
                System.out.print(i);

                if(j < i)
                    System.out.print("*");
            }
            System.out.println();
        }
    }
}