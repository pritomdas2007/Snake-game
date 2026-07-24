class Employee:
    def __init__(self,role,dept,salary):
        self.role=role
        self.dept=dept
        self.salary=salary
    def showdetails(self):
        print("role=",self.role)
        print("department=",self.dept)
        print("salary=",self.salary)
class Engineer(Employee):
    def __init__(self,name,age):
        self.name=name
        self.age=age
        super().__init__("accountant","Finance",600000)

office = Engineer("Pritom",26)
print(office.name)
office.age

office.showdetails()
