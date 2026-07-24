class Account:
    def __init__(self,acc,balance):
        self.acc = acc
        self.balance=balance
        
    def debit(self,amount):
        self.balance-=amount
        print("Rs.",amount,"debited")
        print("TOTAL BALANCE:",self.get_bal())
        
    def credit(self,amount):
        self.balance+=amount
        print("Rs.",amount,"credited")
        print("TOTAL BALANCE:",self.get_bal())
        
    #storing the final balance after credit or debit
    def get_bal(self):         
        return self.balance

acc1 = Account(1234,10000)
acc1.credit(20000)
acc1.debit(10000)
    
