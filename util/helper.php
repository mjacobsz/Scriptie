<?php

	function print_arr($the_arr) {
		$to_print = "";
		foreach ($the_arr as $element) {
			$to_print = $to_print . $element  . " ";
		}
		$to_print = $to_print . "\n";
		print $to_print;
	}

?>
