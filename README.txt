In our first semester, we were asked to develop a Mess Management using the instructions mentiooned in CS103L_AI_Project.pdf.
We were instucted to create a system in c++ without using the concepts of OOP. The same project can be converted to Library Managment system
and hospital management system. PLease! download the "Mess-System.sln" file to get access to the code.
The code uses the concept of file handling and it uses CSV files as its data manager.
1) Inintally, when the program is run, it looks for a file named "data.csv" in its directory, if it doesnt find one, it creates a file and names it "data.csv".
2) once it has found the file, it reads all the data on "data.csv" and loads it onto vectors.
3) using these vectors, we can now edit, delete and sort data as we wish.
4) upon closing the program, all the data loaded on the vecotos is again printed into CSV file.