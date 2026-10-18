**Municipal Financial Management System (MFMS)

Group Members**


|**Student Name**|**Student Number**|**Main Responsibility**|
|-|-|-|
|Student1|225134497|Employee Management|
|Student2|225009064|Budget Management|
|Student3|225150344|Supplier Management|
|Student4|225089963|Assets Management|
|Student5|224091514|Reports|
|Student6|225166577|Functions and Integration|
|Student7|225155303|Testing and Documentation|




**What is the MFMS?**


This is a menu-driven C program built for a municipality. It helps them keep track of their workers, money, suppliers, and physical assets in one place.



The system has 5 main parts:

**1. Employee Management**

Add workers, view the list, search by ID, and see salary stats (average, highest, lowest).



**2. Budget Management**

Add budgets for departments, record spending, and check if a department has gone over their budget.



**3. Supplier Management**

Add suppliers, view the list, and search for them by name.



**4. Asset Management**

Add municipal assets, view the list, and search for them by ID.



**5. Reports**

View summary reports for employees, budgets, suppliers, and assets. You can also view a full system report that combines everything.

**How we Compile**

gcc -std=c99 -c main.c

gcc -std=c99 -c employees.c

gcc -std=c99 -c budget.c

gcc -std=c99 -c suppliers.c

gcc -std=c99 -c assets.c

gcc -std=c99 -c reports.c

gcc -std=c99 -c utilities.c


Then we link them all together into one program:

gcc -o mfms.exe main.o employees.o budget.o suppliers.o assets.o reports.o utilities.o

Then 
mfms.exe

