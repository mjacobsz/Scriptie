<?php

	$begin = microtime(true);
	
	/* Logic goes here... */
	require 'func_defs.php';
	
	foo();
	
	$end = microtime(true);
	$elapsed_time = $end - $begin;
	print("\nElapsed time: $elapsed_time");

?>
