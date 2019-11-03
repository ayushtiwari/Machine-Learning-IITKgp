preprocess:
		python preprocess_data.py

a.out:	preprocess
		g++ -std=c++14 main.cpp

clean:
		rm train.csv
		rm test.csv
		rm a.out
	
run:	a.out
		./a.out
