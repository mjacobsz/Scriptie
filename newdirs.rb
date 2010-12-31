#!/usr/bin/ruby
require "fileutils"

p "Starting..."

# get the current 'highest number dir' number
criterium = "[0-9][0-9]"
largest = Integer(Dir[criterium].max)

# create new dir with new largest number
largest += 1
new_dir_name = largest < 10 ? "0#{largest}" : largest.to_s
Dir.mkdir(new_dir_name)
p "Succesfully created: #{new_dir_name}"

# create subdirs
Dir.mkdir("#{new_dir_name}/in")
Dir.mkdir("#{new_dir_name}/out")
p "Succesfully created the subdirs 'in' and 'out'"

# copy 'compile.sh' and 'run.sh' to the fresh dirs
FileUtils.cp("compile.sh", "#{new_dir_name}/compile.sh")
FileUtils.cp("run.sh", "#{new_dir_name}/run.sh")
p "Copied bash scripts to #{new_dir_name}"

p "Finished!"
# Dont look at the next line... I needed some 'kladpapier'.
# p005195 mremote.science.uva
