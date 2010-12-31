<?php

	include '/home/marvin/school/hiphop/util/helper.php';

	// Generate a Fibonacci sequence of length $length
	function fibonacci($length) {
		$sequence = array(0, 1);
		if( !is_int($length) || $length < 0 ) {
			die("Supply an non-negative integer i, please.\n");
		} else if ($length == 0) {
			array_pop($sequence);
			return $sequence;
		} else if ($length == 1) {
			return $sequence;
		} else {
			for ($i = 2; $i < $length; $i++) {
				$new_val = $sequence[$i - 2] + $sequence[$i - 1];
				$sequence[] = $new_val;
			}
			return $sequence;
		}
	}
	
	$f0 = fibonacci(0);
	print_arr($f0);
	
	$f1 = fibonacci(1);
	print_arr($f1);

	$f2 = fibonacci(3);
	print_arr($f2);

	$f3 = fibonacci(10);
	print_arr($f3);

	$f4 = fibonacci(20);
	print_arr($f4);

	$f5 = fibonacci("Je moeder");
	print_arr($f5);			
?>
