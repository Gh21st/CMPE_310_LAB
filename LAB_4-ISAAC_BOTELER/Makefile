lab_4: aggregate_ints_driver.c aggregate_ints.s
	gcc -no-pie aggregate_ints_driver.c aggregate_ints.s -o lab_4

test: aggregate_ints_tester.c aggregate_ints.s 
	gcc -no-pie aggregate_ints_tester.c aggregate_ints.s -o lab_4_test

debug: aggregate_ints_driver.c aggregate_ints.s
	gcc -g -no-pie aggregate_ints_driver.c aggregate_ints.s -o lab_4_debug

