**Tests Performed**



**Test 1-Main Menu**


run command: mfms.exe.
Expected: Main menu with 6 options appears.
Actual: Menu appeared with all 6 options.
result: pass


**Test 2-Invalid Menu Choice**



run command 99
Expected: "Invalid choice. Try again."
Actual: Message shown, menu came back.
Result: PASS but not in the optin



**Test 3-Add Employee**





Added one employee:
ID: 1
Name: John
Department: Finance
Basic: 15000
Housing: 3000
Transport: 2000
Expected: "Employee added successfully."
actual: Saved correctly.



**Test 4—Reject Negative Salary**



Tried adding an employee with basic salary of -500.
Expected: Reject the value and ask again.
Actual: Message "Salary cannot be negative. Enter again:" shown. Accepted valid value after.
Result: PASS



**Test 5—Display and Search Employees**




Chose display Employees. Then searched by ID 1.
Expected: Table shows all employees. Search finds John.
Actual: Both worked correctly.
Result: pass



**Test 6—Add Budget and Over-Budget Check**



Added Finance: allocated 500000, spent 420000.
Added HR: allocated 300000, spent 350000.
Expected: Finance = WITHIN BUDGET, HR = OVER BUDGET.
Actual: Both flagged correctly.
Result: PASS



**Test 7—Add Supplier**



Added one supplier:
ID: 101
Name: ABC Traders
Email: abc@test.com
Phone: 0811111111
Town: Windhoek
Expected: "Supplier added successfully."
Actual: Saved correctly.
Result: PASS



**Test 8—Add Asset**


Added one asset:
ID: 201
Name: Toyota Hilux
Type: Vehicle
Value: 450000
Department: Works
Condition: Good
Expected: "Asset added successfully."
Actual: Saved correctly.
Result: PASS



**Test 9-Reports**



Opened Reports menu. Ran all four reports: Employee, Budget, Supplier, Asset.
Expected: Each report shows correct summary.
Actual: All four reports correct.
Result: PASS



**Test 10 — Empty Data and Exit**



Restarted the program with no data. Opened Reports.
Then chose Exit (option 6).
Expected: Reports show "no data" messages. Program exits cleanly.
Actual: No crashes. Program exited.
Result: PASS

