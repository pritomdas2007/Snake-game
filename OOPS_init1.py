class Student:
    def __init__(self, name, marks):
        self.name = name
        self.marks = marks

    def display_name(self):
        print("NAME:", self.name)

    def average(self):
        avg = sum(self.marks) / len(self.marks)
        print("AVERAGE MARK:", avg)


# Create object and call methods
s1 = Student("Pritom", [78, 89, 95])
s1.display_name()
s1.average()
