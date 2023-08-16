$sourceFile = "finngrab.cpp"
$outputFile = "finngrab.exe"

$result = & g++ -o $outputFile $sourceFile 2>&1

if ($LASTEXITCODE -eq 0) {
    $process = Start-Process -FilePath .\$outputFile -RedirectStandardOutput output.txt -PassThru
    $process.WaitForExit()

    $output = Get-Content output.txt
    foreach($line in $output){
        Write-Host $line
    }
    
    Remove-Item output.txt
    Remove-Item finngrab.exe
} else {
    Write-Host "Compilation failed. Error Message: $result"
}