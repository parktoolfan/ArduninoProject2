(*define error method*)
on report(ErrorPayload)
	tell application "iTerm"
		create window with default profile
	end tell
	tell application "System Events"
		keystroke "push " & ErrorPayload --using {option down, command down}
		keystroke return
		delay 1
		keystroke "w" using {command down}
	end tell
end report


using terms from application "Messages"
	on message received theMessage from theBuddy for theChat with eventDescription
		try
			set theHandle to handle of theBuddy
			set theContent to eventDescription
			set payload to theHandle & "," & theContent
			
			
			(*
			#Create a push request and send the message content
			display notification "DOING JOB"
			set postRequest to "curl -X POST -H \"Content-Type: application/json\" -d '{\"value1\":\"" & theHandle & "\",\"value2\":\"" & theContent & "\"}' https://maker.ifttt.com/trigger/toArduinoWithPayload/with/key/bLMBpfOKL5alWnYd1MMij3"
			
			tell application "iTerm"
				create window with default profile
			end tell
			
			tell application "System Events"
				keystroke postRequest
				keystroke return
				delay 1
				keystroke "w" using {command down}
			end tell
*)
			set theContentformatted to "bggn" & theContent
			s3write(theContentformatted)
			delay 5
			tell application "Transmit"
				-- In Transmit 4, favorites are now objects and must be specified in a different way. Below
				-- we're choosing the first occurrence of a favorite named "My Great Server"(it's possible to
				-- have multiple favorites with the same name).
				--
				-- Also, the favorites list can only be directly referenced within Transmit's tell block, which is
				-- why we're setting a variable below instead of looking up the favorite within the tab's tell
				-- block.
				
				set myFave to item 1 of (favorites whose name is "S3AmazonArduino")
				set myRules to (skip rules whose name is "New Rule") -- must be a set, not an individual item
				
				-- Create a new window (and thus a single tab) for this script
				tell current tab of (make new document at end)
					connect to myFave
					
					-- Go into the local and remote folders that we want to sync.
					change location of local browser to path "~/Documents/TransmitAmazonS3SyncFolder"
					change location of remote browser to path "arduinoproject"
					
					-- Run a basic sync from the current local folder to the current remote folder. (The sync
					-- command has many options, so be sure to check Transmit's dictionary.)
					synchronize local browser to remote browser using skip rules myRules
					
					-- Close the connection.
					close remote browser
				end tell
			end tell
			
			delay 3
			tell application "Transmit" to quit
			display notification "Data written to S3"
			report("Data written to S3")
		on error errorMessage number errorNumber
			report("errorMessage from write data to S3: " & errorMessage & ", errorNumber: " & errorNumber)
		end try
		
	end message received
	
	
	# The following are unused but need to be defined to avoid an error
	
	on active chat message received from theBuddy for theChat with eventDescription
	end active chat message received
	
	on message sent theMessage with eventDescription
		
	end message sent
	
	on chat room message received with eventDescription
		#	say eventDescription
	end chat room message received
	
	on addressed message received theMessage from theBuddy for theChat with eventDescription
		#		say eventDescription
	end addressed message received
	
	on received text invitation with eventDescription
		#		say eventDescription
	end received text invitation
	
	on received audio invitation theText from theBuddy for theChat with eventDescription
		#		say eventDescription
	end received audio invitation
	
	on received video invitation theText from theBuddy for theChat with eventDescription
		#		say eventDescription
	end received video invitation
	
	on «event ichthe15» given «class hepr»:theBuddy, «class hect»:theChat, «class heed»:eventDescription
		#		say eventDescription
	end «event ichthe15»
	
	on buddy authorization requested with eventDescription
		#		say eventDescription
	end buddy authorization requested
	
	on addressed chat room message received with eventDescription
		#		say eventDescription
	end addressed chat room message received
	
	on «event ichthe16» given «class heed»:eventDescription
		#		say eventDescription
	end «event ichthe16»
	
	on login finished with eventDescription
	end login finished
	
	on logout finished with eventDescription
	end logout finished
	
	on buddy became available with eventDescription
	end buddy became available
	
	on buddy became unavailable with eventDescription
	end buddy became unavailable
	
	on received file transfer invitation theFileTransfer with eventDescription
	end received file transfer invitation
	
	on av chat started with eventDescription
	end av chat started
	
	on av chat ended with eventDescription
	end av chat ended
	
	on completed file transfer with eventDescription
	end completed file transfer
	
end using terms from

on s3write(thisString)
	set this_story to thisString
	set this_file to ("SSDX:Users:theostangebye:Documents:TransmitAmazonS3SyncFolder:" & "s3conversation.txt")
	my write_to_file(this_story, this_file, false)
end s3write

on write_to_file(this_data, target_file, append_data)
	try
		set the target_file to the target_file as string
		set the open_target_file to open for access file target_file with write permission
		if append_data is false then set eof of the open_target_file to 0
		write this_data to the open_target_file starting at eof
		close access the open_target_file
		return true
	on error
		try
			close access file target_file
		end try
		return false
	end try
end write_to_file