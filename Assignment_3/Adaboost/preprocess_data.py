with open("test3_19.csv") as f:
    content = f.readlines()
    
content = [x.strip() for x in content]

#print(content)

with open("test.csv", "w") as f:
    f.write("\n".join(content))
    
    
with open("data3_19.csv") as f:
    content = f.readlines()
    
content = [x.strip() for x in content]

#print(content)

with open("train.csv", "w") as f:
    f.write("\n".join(content))

    
    
    

