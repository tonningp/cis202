all:
	@g++ -std=c++17 -o main *.cpp 2>&1 | tee errors.txt

run: main.cpp
	@./main | tee output.txt

edit:
	@vim -p *.cpp

clean:
	@rm main

git-commit:
	git add .
	git commit -a -m 'update'

git-submit:
	git push
