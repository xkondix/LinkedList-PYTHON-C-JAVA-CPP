class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.prev = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.curr = None 
        self.tail = None

        
    def addEnd(self,data):
        new = Node(data)
        if self.head is None:
            self.head = new
            self.tail= new
            self.head.prev=self.tail
            self.tail.next=self.head
        
        curr = self.tail
        new.prev=self.tail
        self.tail.next=new
        self.tail=new
        self.tail.next=self.head
        self.head.prev=self.tail
        
        
    def addStart(self,data):
        new = Node(data)
        if self.head is None:
            self.head = new
            self.tail= new
            self.head.prev=self.tail
            self.tail.next=self.head
        
        curr = self.head
        new.next=self.head
        self.head.prev=new
        self.head=new
        self.head.prev=self.tail
        self.tail.next = self.head
        
        
    def popStart(self):
        if self.head is None:
            raise IndexError("list is empty")
        elif self.tail==self.head:
            val = self.head.data
            self.head=None
            self.tail=None
            return val
        
        val = self.head.data
        curr = self.head.next
        self.head = curr
        self.head.prev=self.tail
        self.tail.next = self.head
        return val
        
        
    def popEnd(self):
        if self.head is None:
            raise IndexError("list is empty")
        elif self.tail==self.head:
            val = self.head.data
            self.head=None
            self.tail=None
            return val
        
        val = self.tail.data
        curr = self.tail.prev
        self.tail = curr
        self.tail.next=self.head
        self.head.prev = self.tail
        return val
        
        

    def insert(self,data,i):
        new = Node(data)
        counter = 0
        if self.head is None:
            self.head = new
            self.tail= new
            self.head.prev=self.tail
            self.tail.next=self.head
            return
        elif i == counter:
            self.addStart(data);
            return  
        else:
            curr = self.head.next
            counter+=1

            while curr!=self.head:
                if i == counter:
                    
                    prevNode = curr.prev
                    prevNode.next=new
                    new.prev=prevNode
                    curr.prev=new
                    new.next=curr
                    return
                counter+=1
                curr = curr.next
                
            if counter==i:
                return self.addEnd(data)

            
            
    def delete(self,i):
        counter = 0
        if self.head is None:
            raise IndexError("list is empty")
        elif i == counter:
            return self.popStart()
        
        else:
            curr = self.head.next
            while curr!=self.head:
                counter+=1
                if i == counter:
                    if curr==self.tail:
                        return self.popEnd()
                    else:
                        val = curr.data
                        prevNode=curr.prev
                        nextNode=curr.next
                        prevNode.next=nextNode
                        nextNode.prev=prevNode
                        return val
                curr = curr.next
            
    def __iter__(self):
        return self
        
    def __next__(self):
        if self.head and not self.curr:
            self.curr = self.head
            return self.curr.data
        try:
            if self.curr.next!=self.head:
                self.curr = self.curr.next
                return self.curr.data
        except AttributeError:
            raise StopIteration("list is empty")

            
        else:
            self.curr=None
            raise StopIteration
        

    def __str__(self):
        curr = self.head
        
        if curr == None:
            return "[]"
        
        table=[]
        while curr:
            #print(curr.prev.data,curr.data,curr.next.data)
            table.append(curr.data)
            curr = curr.next
            if curr == self.head:
                return str(table)

                
    
    def __repr__(self):
        return self.__str__()

    

if __name__ == "__main__": 
    s = LinkedList()
    
    s.addEnd(1)
    print(s)

    s.addEnd(2)
    s.popEnd()
    s.popEnd()
    print(s)

    s.addEnd(3)
    print(s)

    s.addStart(4)
    print(s)

    s.addStart(5)
    print(s)

    s.addStart(6)
    print(s)
    
    s.insert(22,1)
    print(s)
    
    s.insert(22,1)
    print(s)
    
    s.delete(6)
    print(s)
    
    s.popStart()
    print(s)
    
    s.popStart()
    print(s)
    
    s.delete(1)
    print(s)
    
    
#     print("--------------------------")
    
#     for i in s:
#         print(i)
        
#     print("--------------------------")
        
#     kk=LinkedList()
#     for i in kk:
#         print(i)
        
#     print("--------------------------")
        
#     m=LinkedList()
#     m.popEnd()
    
    
#     print("--------------------------")
        
#     m=LinkedList()
#     m.popStart()
    
        
    
