<?php

	$begin = microtime(true);
	
	/* Logic goes here... */
	echo "Bonjour, Monde!";
	
	$end = microtime(true);
	$elapsed_time = $end - $begin;
	print("Elapsed time: $elapsed_time\n");

?>
